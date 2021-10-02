/*
This algorithm is based on topological sort to find the 
shortest path from the source node to every other node in O(V+E) 
time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>  graph;
vector<bool > vis;
stack<int>  topostack;

void dfs(int node){
      vis[node]= true;
      for(auto a: graph[node]){
            if(!vis[a.first])
                  dfs(a.first);
      }
      topostack.push(node);
}
void runAllDFS(){
      for(int i=0;i<graph.size();i++){
            if(!vis[i])dfs(i);
      }
}
// upper code is to find the topological sort.
vector<int> dist;

void traverseChildren(int node){
    // It just traverse all the edges of the particular node.
    if(dist[node]==INT_MAX)return;
    for(auto a: graph[node]){
        if(dist[node]+a.second<dist[a.first]){
            dist[a.first]= dist[node]+a.second;
        }
    }
}

int main(){
      vis.resize(4,false);
      dist.resize(4,INT_MAX);
      graph.push_back({{1,1}});
      graph.push_back({{2,3},{3,2}});
      graph.push_back({{3,4}});
      graph.push_back({});
      runAllDFS();
      vector<int > toposorted;
      while(!topostack.empty()){
            int top= topostack.top();
            topostack.pop();
            toposorted.push_back(top);
      }

      int source =1; 
      dist[source]=0;
      for(int i=0;i<toposorted.size();i++){
            traverseChildren(toposorted[i]);
      }
      for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<" ";
      }
}