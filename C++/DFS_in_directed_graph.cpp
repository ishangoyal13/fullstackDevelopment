#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
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

vector<vi> adj;
int tim = 1;
vi vis_time;

void dfs(int i, vi &vis)
{
    cout << i << ' ' << tim << '\n';
    tim++;
    vis[i] = 1;
    vis_time[i] = tim;

    for (int nb : adj[i])
    {
        if (!vis[nb])
        {
            // Tree Edge;
            dfs(nb, vis);
        }

        else if (vis[nb] == 1)
        {
            //Back Edge;
            cout << "back edge\n";
        }

        else if (vis_time[nb] > vis_time[i])
        {
            // Forward Edge;
            cout << "forward edge\n";
        }

        else
        {
            //Cross Edge;
            cout << "Cross edge\n";
        }
    }
    // mark it as 2 to signify it is out of call stack
    vis[i] = 2;
}

int32_t main()
{
    int n, m;
    // n is number of nodes in graph
    //  m is the number of edges in the graph
    // adj is the adjacency list for the graph
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        adj[i].pb(j);
    }
    vi vis(n + 1, 0);
    vis_time.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        //  if the current node has not been visited before then perform dfs from it
        if (!vis[i])
            dfs(i, vis);
}