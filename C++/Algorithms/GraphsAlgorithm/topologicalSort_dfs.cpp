#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
stack<int> stk;
vector<int> vis;

void dfs(int node){
      vis[node]=true;
      for(auto sub: graph[node]){
            if(!vis[sub])dfs(sub);
      }
      stk.push(node);
}

void findTopoSort(){
      for(int i=0;i<graph.size();i++){
            if(!vis[i])dfs(i);
      }
}

int main(){
      vis.resize(5,false);
      graph.push_back({3,2});
      graph.push_back({3,4});
      graph.push_back({3});
      graph.push_back({1,2});
      graph.push_back({2});
      findTopoSort();
      while(!stk.empty()){
            int top= stk.top();
            stk.pop();
            cout<<top<< " "; 
      }
}