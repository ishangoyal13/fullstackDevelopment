// Bellman Ford's algorithm is used to find the 
// minimum Distance form source vertex to every other vertex.
// It handle the case with "negative weight Edge" which Dijkstra can't.

//  It can be modified to report if there exist any (-)ve weight cycle.
// It can also be modified to find shortest distance between all pairs of nodes.
#include<bits/stdc++.h>
using namespace std;

#define f first
#define se second

vector<vector<pair<int,int>>> graph;// Directed
vector<pair<pair<int,int>,int>> graphEdges;
vector<int> dist;
vector<bool> vis;

void addEdge(int u,int v,int w){
    graph[u].push_back(make_pair(v,w));
}
void findEdges(){
    vis.resize(graph.size(),false);
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            graphEdges.push_back({{i,graph[i][j].f},graph[i][j].se});
        }
    }
}

void BellManFord(){
      dist.resize(graph.size(),INT_MAX);
      int V= graph.size();
      dist[0] =0 ;
      for(int i=0;i< V-1;i++){
            for(auto edg: graphEdges){
                  if(dist[edg.f.se]>dist[edg.f.f]+edg.se){
                        dist[edg.f.se]= dist[edg.f.f]+ edg.se;
                  }
            }
      }
}

void solve(){



}



int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,e,u,v,w;
    cin>>n>>e;
    graph.resize(n);
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    findEdges();
    BellManFord();
    for(int i=0;i<dist.size();i++){
        cout<<i<<" "<<dist[i]<<"\n";
    }
}