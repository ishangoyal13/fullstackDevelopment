#include <bits/stdc++.h>
using namespace std;
 
#define mod 10000007
#define int long long 
#define N 200001
 
std::vector<int> adj[N];
int vis[N];
int ans=0; 
void dfs(int curr, int prev){
    for(auto i:adj[curr]){
        if(i!=prev){
            dfs(i,curr);      
            if(!vis[i] && !vis[curr]) ans++,vis[i]=1,vis[curr]=1;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0);
        cout<<ans;
    }
}