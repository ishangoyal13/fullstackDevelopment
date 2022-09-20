// Kosaraju's algorithm is used to find all strongly 
// component in a graph. In a strongly connected component 
// each node can visit all other node and vice versa.
// Kosaraju's algorithm is used to find all strongly 
// component in a graph. In a strongly connected component 
// each node can visit all other node and vice versa.
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
vector<vector<int>> graphT;
vector<int> vis;
stack<int> stk;

void dfs1(int node){
      vis[node] = true;
      for(auto sub: graph[node])
            if(!vis[sub])dfs1(sub);  
      stk.push(node);
}

vector<int> currSCC;
void dfs2(int node){
      vis[node] = true;
      currSCC.push_back(node);
      for(auto sub: graphT[node])
            if(!vis[sub])dfs2(sub);
}

vector<vector<int>> getSCC(){
      // Below is the code for sorting the graph in completion time basis.
      vis.assign(N,false);
      int V= graph.size();
      for(int i=0;i<V;i++)
            if(!vis[i])dfs1(i);

      // Traverse the reversed graph in order as stk.
      vis.clear();
      vis.assign(N,false);
      vector<vector<int>> allSCC;
      while(!stk.empty()){
            int i = stk.top();
            stk.pop();
            if(!vis[i]){
                  currSCC.clear();
                  dfs2(i);
                  allSCC.push_back(currSCC);
            }
      }
      clear();
      return allSCC;
}
void clear(){
      // graph.clear();
      graphT.clear();
      currSCC.clear();
      vis.clear();
      while(!stk.empty())stk.pop();
}
void addedg(int u,int v){
      graph[u].push_back(v);
      graphT[v].push_back(u);
}

int main(){
      #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin); 
            freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr), cout.tie(nullptr);

      N = 5;
      graph.resize(N);
      graphT.resize(N);

      addedg(1,0);
      addedg(0,2);
      addedg(2,1);
      addedg(0,3);
      addedg(3,4);
      vector<vector<int>> scc = getSCC();
      for(auto x: scc){
            for(auto y: x){
                  cout << y << ' ';
            }cout << '\n';
      }
}

// OUTPUT
// 0 1 2 
// 3 
// 4 