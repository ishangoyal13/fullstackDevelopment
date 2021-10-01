#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define FOR(i, a, b, c) for (ll i = a; i < b; i += c)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define lc(x) (x << 1)
#define rc(x) ((x << 1) | 1)
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define range(a, b) substr(a, b - a + 1)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define epsilon 1e-9
#define sign(x) (x > 0) - (x < 0)
#define is_poweroftwo(n) (n && !(n & (n - 1)))
typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

const int N = 3e5 + 10;
vector<int> g[N];

vi U(N), V(N), W(N), par(N);
vector<ll> d(N, inf);

int adj(int x, int e)
{
    return U[e] ^ x ^ V[e];
}

// start is the node from which we are starting
// d stores the  shortest distances from start
// n is the number of nodes in the graph
// par array stores the path
// uses edge list
int dijkstra(int start, vi &d, int n)
{
    vector<bool> vis(n + 1, false);
    d[0] = inf;
    d[start] = 0;
    set<pair<ll, int>> S;
    S.insert({d[start], start});
    while (!S.empty())
    {
        auto it = *S.begin();
        S.erase(S.begin());
        int x = it.ss;
        if (vis[x])
            continue;

        vis[x] = 1;
        for (auto e : g[x])
        {
            int y = adj(x, e);
            if (d[x] + W[e] < d[y])
            {
                par[y] = x;
                d[y] = d[x] + W[e];
                S.insert({d[y], y});
            }
        }
    }
    if (d[n] == inf)
    {
        d[n] = -1;
    }
    return 0;
}
int multisource(vi sources, vi &d, int n)
{
    vector<bool> vis(n + 1, false);
    d = std::move(vector<long long>(n + 1, inf));
    set<pair<ll, int>> S;
    for (auto source : sources)
    {
        d.at(source) = 0;
        S.insert({0, source});
    }
    while (!S.empty())
    {
        auto it = *S.begin();
        S.erase(S.begin());
        int x = it.ss;
        if (vis[x])
            continue;

        vis[x] = 1;
        for (auto e : g[x])
        {
            int y = adj(x, e);
            if (d[x] + W[e] < d[y])
            {
                par[y] = x;
                d[y] = d[x] + W[e];
                S.insert({d[y], y});
            }
        }
    }
    if (d[n] == inf)
    {
        //cout<<"-1"<<endl;
        d[n] = -1;
    }
    return 0;
}
// for adjacency list of vector<vector<pair<int,int>>>adj
// stores node, weight pair
// returns distance array
// par stores the parent array giving the shortest path spanning tree
vi dijkstra(int src, int n, vector<vector<pair<int, int>>> adj)
{
    vi d(n + 1, inf), par(n + 1);
    set<pii> s; //first->d, second->node

    d[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {
        auto it = s.begin();
        int u = it->ss;

        s.erase(it);

        for (pii e : adj[u])
        {
            int nb = e.ff, w = e.ss;

            if (d[u] + w < d[nb])
            {
                s.erase({d[nb], nb});
                d[nb] = d[u] + w;
                par[nb] = u;
                s.insert({d[nb], nb});
            }
        }
    }

    return d;
}
// using priority queue and adjacency list
vi dijikstra(int src, vector<vector<pair<int, int>>> adj, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, inf);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    vector<bool> f(n + 1, false);
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = (pq.top()).ss;
        pq.pop();
        f[u] = true;

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorted path to v through u.
            if (f[v] == false && dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n + 1; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    return dist;
}
signed main()
{
    FIO;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijikstra(0, adj, n);

    return 0;
}