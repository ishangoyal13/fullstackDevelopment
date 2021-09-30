
import java.util.*;
import java.lang.*;
import java.io.*;

class Prims_algo 
{
    private static final int V = 5;
    int minKey(int key[], Boolean mstSet[])
    {
        int min = Integer.MAX_VALUE, min_index = -1;
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min) 
            {
                min = key[v];
                min_index = v;
            }
        return min_index;
    }
    
    void printMST(int parent[], int graph[][])
    {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < V; i++)
            System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
    }
    
    void primMST(int graph[][])
    {
        int parent[] = new int[V];
        int key[] = new int[V];
        Boolean mstSet[] = new Boolean[V];
        for (int i = 0; i < V; i++) 
        {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) 
        {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) 
                {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
        }
        printMST(parent, graph);
    }
    
    public static void main(String[] args)
    {
        System.out.print('\f');
        Scanner sc = new Scanner(System.in);
        Prims_algo tree = new Prims_algo();
        System.out.println("Enter the number of vertices");
        int vertices = sc.nextInt();
        int x;
        int graph[][] = new int[vertices][vertices];
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                System.out.println("Enter the weight of the egde between " + i +" " +j);
                x = sc.nextInt();
                graph[i][j] = x;
            }
        }
        long start = System.nanoTime();
        tree.primMST(graph);
        long end = System.nanoTime();
        long microseconds = (end - start) / 1000;
        System.out.println("Time for MST using prim's algo in micro seconds is "+microseconds);

    }
}