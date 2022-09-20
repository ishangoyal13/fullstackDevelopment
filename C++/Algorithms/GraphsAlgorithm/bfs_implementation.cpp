#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool vis[10005];
vector<vector<int>> graph;

void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node]=true;
    while(!q.empty()){
        int temp= q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto a: graph[temp]){
            if(!vis[a]){
                q.push(a);
            }
            vis[a]=true;
        }
    }
}

void _if_graph_is_disconnected(void (*function)(int)){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<graph.size();i++){
        if(!vis[i]){
            function(i);
        }
    }
}
int main(){
    memset(vis,false,sizeof(vis));

    graph.push_back({1,2,3});
    graph.push_back({0});
    graph.push_back({0,3,5});
    graph.push_back({0,2,4,5});
    graph.push_back({3});
    graph.push_back({2,3});
    _if_graph_is_disconnected(&bfs);
    _if_graph_is_disconnected(&dfs);
}


