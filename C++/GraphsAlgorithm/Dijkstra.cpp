// This algorithm is almost identical to the prims algorithm.
// The only difference is the in case of prim our min[] was storing min of the 
// weight of adjecent edge. But here we are storing minimun of min of the weight of 
// adjecent+distance of adjecent from source.
// if(!vis[v] && curMIN[v]> weight ) in case of Prim.
// if(!vis[v] && minDIST[v] > minDIST[u] + uvDist) in case of Dijkstra

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;

void addEdge(int u, int v, int weight){
    graph[u].push_back({v,weight});
    graph[v].push_back({u,weight}); // If we comment this line it will work for directed Edges.
}

void dijkstra(){
    int V= graph.size();
    vector<int> minDIST(V,INT_MAX);
    vector<bool> vis(V , false);
    int src= 0;
    minDIST[src]= 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int u= pq.top().second;
        int d= pq.top().first;
        pq.pop();
        if(vis[u])continue; // either this can be use to aviod TLE.
        vis[u] = true;
        // if(minDIST[u]<d)continue; // to avoid TLE
        for(auto sub : graph[u]){
            int v = sub.first;
            int uvDist= sub.second;
            if(!vis[v] && minDIST[v] > minDIST[u] + uvDist){
                minDIST[v] = minDIST[u] + uvDist;
                pq.push({minDIST[v], v});
            }
        }
    }
    for(int i=0;i< V; i++){
        cout<<"i = "<<i<<" dis= "<<minDIST[i]<<"\n";
    }
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
    dijkstra();
}
// Sample Input
// 9 14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 8 2
// 2 5 4
// 3 4 9
// 3 5 10
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7
