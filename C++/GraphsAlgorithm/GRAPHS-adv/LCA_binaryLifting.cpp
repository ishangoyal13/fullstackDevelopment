/*
Topic: LCA using Binary Lifting.
*/
#include<bits/stdc++.h>
using namespace std;

struct LCA{
      vector<vector<int>> graph;
      vector<vector<int>> lca;
      vector<int> depth;
      int maxDepth;
      LCA(int n, vector<vector<int>> _graph, int root=1){
            graph = _graph;
            depth.resize(n+1,-1);
            maxDepth = log2(n);
            lca.resize(n+1, vector<int>(maxDepth+1, -1)); 
            // lca[i][j] will store the 2^j parent of i.
            sup_dfs(root,-1,0); // this dfs will calculate both parent and depth
            for(int pow=1; pow<=maxDepth; pow++){
                  for(int i=1; i<=n; i++){
                        if(lca[i][pow-1]!=-1){
                              lca[i][pow] = lca[lca[i][pow-1]][pow-1];
                        }
                  }
            }
      }
      void sup_dfs(int node, int parent, int d){
            lca[node][0] = parent;
            depth[node] = d;
            for(auto child: graph[node]){
                  if(child!=parent){
                        sup_dfs(child, node, d+1);
                  }
            }
      }
      int query(int a, int b){
            if(depth[a] < depth[b]) swap(a,b);
            int d = depth[a]-depth[b];
            while(d>0){
                  int jump = log2(d);
                  a = lca[a][jump];
                  d -= (1<<jump);
            }
            if( a==b ) return a;
            int jump = maxDepth;
            while(jump >= 0){
                  if(lca[a][jump]!=-1 and lca[a][jump]!=lca[b][jump]){
                        a = lca[a][jump];
                        b = lca[b][jump];
                  }
                  jump--;
            }
            return lca[a][0];
      }
}; 

void south_pole(){
      int i,n,e;
      cin >> n ;
      vector<vector<int>> graph(n+1);
      for(int i=1;i<=n;i++){
            int noofChilds;
            cin >> noofChilds ;
            for(int j=0;j<noofChilds;j++){
                  int v;
                  cin >> v;
                  graph[i].push_back(v);
                  graph[v].push_back(i);
            }
      }
      LCA lca(n,graph);
      int q;
      cin >> q;
      while(q--){
            int a,b;
            cin >> a >> b;
            cout << lca.query(a, b) << '\n';
      } 
}


int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1,caseno=1;
    cin >> t;
    while(t--) {
        cout << "Case "<<caseno<<":\n";
        south_pole();
        caseno++;
    }
    // timer();
    return 0;
}