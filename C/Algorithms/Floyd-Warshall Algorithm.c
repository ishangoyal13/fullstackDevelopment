Program in C to use the Floyd-Warshall Algorithm to find out the shortest path between every pair of nodes in the graph. Then take 2 nodes as input and find out the path between them as well as the path length.

  #Floyd-Warshall Algorithm is an algorithm based on dynamic programming technique to compute the shortest path between all pair of nodes in a graph.

 #Limitations:

The graph should not contain negative cycles.
The graph can have positive and negative weight edges.
For a graph with vertices:

 #Algorithm
Initialize the shortest paths between any 2 vertices with Infinity (INT.maximum).
Find all pair shortest paths that use 0 intermediate vertices, then find the shortest paths that use 1 intermediate vertex and so on, until using all N vertices as intermediate nodes.
Minimize the shortest paths between any pairs in the previous operation.
For any 2 vertices i and j, one should actually minimize the distances between this pair using the first K nodes, so the shortest path will be: minimum( D[i][k] + D[k][j], D[i][j]).

  #Complexity
Worst case time complexity: Θ(V^3)
Average case time complexity: Θ(V^3)
Best case time complexity: Θ(V^3)
Space complexity: Θ(V^2)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int **Wt;   //Weight Matrix
int ***W;   //Array of Weight Matrices
int v;  //number of vertices
int ***origin;  //Parent of a node in the Shortest Path Tree
const int INF=10000;
void insert_edges() //Function to enter edges in our graph
{
    int v1,v2,f=1, w;
    printf("\nEntering Edges: Enter -999 to Terminate---->");
    while(f)
    {
        printf("\nEnter an Edge: ");
        scanf("%d %d", &v1, &v2);
        if(v1==-999 || v2==-999)    //User wants to stop entering edges
        {
            f=0;
            break;
        }
        else
        {
            printf("Enter Weight: ");
            scanf("%d", &w);
            Wt[v1][v2]=w;
            Wt[v2][v1]=w;   //remove this statement for a directed graph
            W[0][v1][v2]=w;
            W[0][v2][v1]=w; //remove this statement for a directed graph
        }
    }
}
void display()  //Display the Adjacency Matrix and the Weight Matrix
{
    int i,j;
    printf("\nWeight Matrix--->\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d\t", Wt[i][j]);
        }
        printf("\n");
    }
}
void floyd_warshall()   //Floyd-Warshall Algorithm
{
    int k,i,j,a,b;
    int n=v;
    for(k=0;k<n;k++)
    {
        printf("\nIntermediate Weight Matrix-%d---->\n",(k+1));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)    //no self loops allowed
                {
                    W[k+1][i][j]=0;
                    origin[k+1][i][j]=-1;
                }
                else
                {
                    a=W[k][i][j];
                    b=W[k][i][k]+W[k][k][j];
                    if(a<=b)    /*existing path length is smaller than or equal to path with a new intermediary node*/
                    {
                        W[k+1][i][j]=a;
                        origin[k+1][i][j]=origin[k][i][j];
                    }
                    else    /*existing path length is bigger than path with a new intermediary node*/
                    {
                        W[k+1][i][j]=b;
                        origin[k+1][i][j]=origin[k][k][j];
                    }
                }
            }
            for(j=0;j<n;j++)
            {
                printf("%d\t", W[k+1][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }  
}
void print_all_pairs_shortest_path(int i, int j)    //Function to print shortest path
{
    if(i==j)
    {
        printf("%d", i);
    }
    else if(origin[v][i][j]==-1)
    {
        printf("No Path Exists between %d to %d\n",i,j);
    }
    else
    {
        print_all_pairs_shortest_path(i, origin[v][i][j]);
        printf("--->%d", j);
    }
}
int main()
{
    int i,j,k,v1,x,y;
    //Enter the number of vertices
    printf("Enter the number of Vertices: ");
    scanf("%d", &v);
    v1=v+1;
    //declare the necessary arrays and matrices
    Wt=(int**)malloc(v*sizeof(int*));    //Weight matrix: a 3D Matrix
    W=(int***)malloc(v1*sizeof(int**));  //Array of Weight Matrices
    origin=(int***)malloc(v1*sizeof(int**));  //Array of Parent Matrices
    for(i=0;i<v;i++)
    {
        Wt[i]=(int*)malloc(v*sizeof(int));
        for(j=0;j<v;j++)
        {
            Wt[i][j]=-1;    //Initialize
        }
    }
    for(k=0;k<v1;k++)
    {
        W[k]=(int**)malloc(v*sizeof(int*));
        origin[k]=(int**)malloc(v*sizeof(int*));
        for(i=0;i<v;i++)
        {
            W[k][i]=(int*)malloc(v*sizeof(int));
            origin[k][i]=(int*)malloc(v*sizeof(int));
            for(j=0;j<v;j++)
            {
                W[k][i][j]=INF; //Initialize
                if(i==j)
                {
                    origin[k][i][j]=-1; //Initialize
                }
                else
                {
                    origin[k][i][j]=i; //Initialize
                }
            }
        }
    }
    insert_edges(); //insert edges
    display();  //display weight matrix   
    floyd_warshall();   //perform the floyd-warshall algorithm
    //Final Path Distance Matrix
    printf("\nFinal Solution Matrix---->\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d\t",W[v][i][j]);
        }
        printf("\n");
    }
    //Print The Path between 2 Nodes
    printf("\nPath Printing Time---->\n");
    printf("Enter Starting Node: ");
    scanf("%d", &x);
    printf("Enter Ending Node: ");
    scanf("%d", &y);
    print_all_pairs_shortest_path(x, y);
    printf("\nPath Length: %d", W[v][x][y]);
} 
