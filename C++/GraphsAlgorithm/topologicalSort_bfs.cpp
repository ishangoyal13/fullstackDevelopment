//Kahn's Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> inDegree;
vector<bool> vis;

void calcInDegree(){
    for(int i=0;i<inDegree.size();i++)
        for(int a: graph[i])
            inDegree[a]++;
}

vector<int> findTopoSort(){
    calcInDegree();
    queue<int> q;
    vector<int> topoSort;
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int temp= q.front();
        q.pop();
        topoSort.push_back(temp);
        for(auto a: graph[temp]){
            if(inDegree[a]>0){
                inDegree[a]--;
                if(inDegree[a]==0)q.push(a);
            }
        }
    }
    return topoSort;
}

int main(){
    vis.resize(5,false);
    inDegree.resize(5,0);
    graph.push_back({2,3});
    graph.push_back({3,4});
    graph.push_back({3});
    graph.push_back({});
    graph.push_back({});
    vector<int> toposort= findTopoSort();
    for(auto t: toposort){
        cout<<t<<" ";
    }
}