// It works for both directed and undirected graph.
#include <bits/stdc++.h>
using namespace std;

bool vis[10005];
bool funcStack[10005];
vector<vector<int>> graph;

bool dfs(int node){
    vis[node]=true;
    funcStack[node]=true;
    // cout<<node<<" ";
    for(auto sub: graph[node]){
        if(!vis[sub])
            if(dfs(sub))
                return true;
        
        if(funcStack[sub])
            return true;
    }
    funcStack[node]=false;
    return false;
}
bool _if_graph_contain_cycle(bool (*function)(int)){
    memset(vis,false,sizeof(vis));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<graph.size();i++){
        if(!vis[i]){
            if(function(i)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    memset(vis,false,sizeof(vis));

//     graph.push_back({1});
//     graph.push_back({});
//     graph.push_back({1,3});
//     graph.push_back({4});
//     graph.push_back({5});
//     graph.push_back({1});
    // _if_graph_is_disconnected(&bfs);
    graph.push_back({1});
    graph.push_back({0});
    if(_if_graph_contain_cycle(&dfs)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}