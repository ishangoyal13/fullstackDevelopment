#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define mod 1000000007
#define inf 1e18
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int n, m;
vector<vi> adj;
bool dfs_for_topo(int i, vi &ans, vi &vis)
{
    vis[i] = 1;

    for (int &nb : adj[i])
    {
        if (vis[nb] == 0)
        {
            bool exists = dfs_for_topo(nb, ans, vis);

            if (!exists)
                return false;
        }

        else if (vis[nb] == 1)
            return false;
    }

    vis[i] = 2, ans.pb(i);
    return true;
}

vi topo_by_dfs()
{
    vi vis(n + 1), ans;
    bool possible = true;

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            possible &= dfs_for_topo(i, ans, vis);

    reverse(ans.begin(), ans.end());
    return possible ? ans : vector<int>{};
}

vi topo_by_bfs()
{
    queue<int> q;
    vi indeg(n + 1), ans;

    for (int i = 1; i <= n; ++i)
        for (int &j : adj[i])
            indeg[j]++;

    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int i = q.front();
        ans.pb(i), q.pop();

        for (int &j : adj[i])
        {
            indeg[j]--;

            if (indeg[j] == 0)
                q.push(j);
        }
    }

    return ans.size() < n ? vi{} : ans;
}

vi lexico_smallest_topo_by_bfs()
{
    pqs q;
    vi indeg(n + 1), ans;

    for (int i = 1; i <= n; ++i)
        for (int &j : adj[i])
            indeg[j]++;

    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int i = q.top();
        ans.pb(i), q.pop();

        for (int &j : adj[i])
        {
            indeg[j]--;

            if (indeg[j] == 0)
                q.push(j);
        }
    }

    return ans.size() < n ? vi{} : ans;
}

int32_t main()
{
    FIO;
    //  n is the number of nodes in the graph.
    //  m is the number of edges in the graph.
    //  adj is the adjacency list
    cin >> n >> m;
    adj.resize(n + 1);

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        adj[i].pb(j);
    }

    vi ans = lexico_smallest_topo_by_bfs();

    for (int &i : ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}