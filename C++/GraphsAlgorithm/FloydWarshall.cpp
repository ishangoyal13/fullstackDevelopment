// This algorithm is used to find shortest path between all 
// pairs of nodes.
// It is having a complexity of O(n^3)
#include<bits/stdc++.h>
using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,l,r)  for(i=l ; i<=r ; i++)
typedef long long ll;
typedef vector<ll>		vl;
typedef vector<vl>		vvl;
const ll INF = 1e10+1;


vvl dist;
vvl graph;

void floydWarshall(int n){
      // assuming 0 based indexing.
      int i,j,k;
      rep(i,0,n-1){
            rep(j,0,n-1){
                  rep(k,0,n-1){
                  if (d[j][i] < INF && d[i][k] < INF)
                        dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
                  }
            }
      }
}

void south_pole(){
    int i,n,e;
    cin >> n >> e;

    graph.reserve(n+1,vl(n+1,INF));
    dist.reserve(n+1,vl(n+1,INF));
    rep(i,0,n-1){
        dist[i][i]=0;
        graph[i][i]=0;
    }
    int u,v,dis;
    rep(i,0,e-1){
        cin >> u >> v >> dis;
        graph[u][v]= dis;
        dis[u][v]=dis;
    }
    floydWarshall(n);
}

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    // timer();
    return 0;
}