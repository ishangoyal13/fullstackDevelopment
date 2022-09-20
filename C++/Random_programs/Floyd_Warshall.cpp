#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > Floyd_Warshall(vector<vector<int> >& graph,int& nodes){
   
   //Initializing all distances as Infinity(very high value)
   vector<vector<int> >dist(nodes+1,vector<int>(nodes+1,INT_MAX));
   
   //Initializing the distance between two nodes as their edge length if there exists an edge
   for(int i=1;i<=nodes;i++){
     for(int j=1;j<=nodes;j++){
       if(graph[i][j]==1)dist[i][j]=1;
     }
   }

   for(int i=1;i<=nodes;i++)dist[i][i]=0;
    
   for(int k=1;k<=nodes;k++){
    for(int i=1;i<=nodes;i++){
      for(int j=1;j<=nodes;j++){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
   }
   return dist;
}

int main(){

   // Taking #nodes and edges as input
   int nodes,edges;
   cin>>nodes>>edges;
   
   vector<vector<int> >graph(nodes+1,vector<int>(nodes+1,0));
   
   // Taking edges and length between them as input
   for(int i=1;i<=edges;i++){
     int x,y,len;
     cin>>x>>y>>len;
     graph[x][y]=len;
     graph[y][x]=len;
   }
   
   //Calling the Floyd Warshall function
   vector<vector<int> >dist = Floyd_Warshall(graph,nodes);

   int queries;
   cin>>queries;

   // answering queries
   while(queries--){
     int node1,node2;
     cin>>node1>>node2;
     cout<<dist[node1][node2];
   }
}
