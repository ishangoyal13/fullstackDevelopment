#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r)  for(int i=l ; i<=r ; i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

void solve(){
      int n,m,q;
      vvl dist;

      cin >> n >> m >> q;
      ll u, v, w;
      dist.resize(n+5,vl(n+5,1e18));
      while(m--){
            cin >> u >> v >> w;
            dist[u][u] = 0;
            dist[v][v] = 0;
            dist[u][v]=min(dist[u][v],w);
            dist[v][u]=min(dist[u][v],w);
      }

      // Floyd Warshall kind of technique.
      rep(k,1,n){
            rep(i,1,n){
                  rep(j,1,n){
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                  }
            }
      }
      while(q--){
            cin >> u >> v;
            if(dist[u][v]!=1e18){
                  cout<<dist[u][v];
            }else{
                  cout<<-1;
            }
            cout<<endl;
      }
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
  return 0;
}