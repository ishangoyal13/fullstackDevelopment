// The time complexity of this algorithm is O(ElogV) 
/*
For finding :- MST (Minimum spanning tree).
The approach of this algorithm is just as Prim algo sound like.
We have collection of edges from the selected nodes in the priority queue.
The next edge will be the edge with smallest weight. 
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
void addEdge(int u, int v, int weight){
    graph[u].push_back({v,weight});
    graph[v].push_back({u,weight});
}

void findMST(){
      int V = graph.size();
      vector<bool> vis(V , false);
      vector<int> curMIN(V , INFINITY);
      priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
      vector<int> parent(V , -1);

      int src=0;
      pq.push({0,src});
      curMIN[src]=0;
      while(!pq.empty()){
            int u= pq.top().second; //min wieght Edge.
            pq.pop();
            vis[u] = true;
            for(auto ch: graph[u]){
                  int v= ch.first;
                  int weight = ch.second;
                  if(!vis[v] && curMIN[v]> weight ){
                        curMIN[v] = weight;
                        parent[v] = u;
                        pq.push({weight,v});
                  }
            }
      }

      for(int i=1;i< V;i++){
            cout<<"\n"<<parent[i]<<" - "<<i;
      }
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    graph.resize(9);
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
    
    // graph.resize(3);
    // addEdge(0,1,5);
    // addEdge(0,2,1);
    // addEdge(2,1,1);
    findMST();
}





