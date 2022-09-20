// It work only if graph is undirected.
#include<bits/stdc++.h>
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
//modifying dfs to detect cycle
bool dfs(int node,int parent){
    vis[node]=true;
    cout<<node<<" ";
    for(auto sub: graph[node]){
        if(!vis[sub]){
            dfs(sub,node);
        }
        else if(sub!=parent){
            return true;
        }
    }
    return false;
}
bool _if_graph_contain_cycle(bool (*function)(int,int)){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<graph.size();i++){
        if(!vis[i]){
            if(function(i,-1)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    memset(vis,false,sizeof(vis));

    graph.push_back({1,2});
    graph.push_back({0,5});
    graph.push_back({0,3});
    graph.push_back({2,4});
    graph.push_back({3,5});
    graph.push_back({4,1});
    // _if_graph_is_disconnected(&bfs);
    if(_if_graph_contain_cycle(&dfs)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}