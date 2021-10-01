import java.util.*;

public class Dijkstra_Algorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        int mat[][] = new int[E][E];
        for (int i = 0; i < E; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            mat[src][dest] = weight;
            mat[dest][src] = weight;
        }
        sc.close();
        dijkstra(mat, V);

    }

    static void dijkstra(int[][] mat, int V) {
        boolean visited[] = new boolean[V];
        int distance[] = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[0] = 0;
        for (int i = 0; i < V; i++) {
            if (visited[i])
                continue;

            int minElem = findMinElem(distance, visited);
            if (minElem == -1)
                continue;

            visited[minElem] = true;

            // Visiting neighbours and updating values
            for (int j = 0; j < V; j++) {
                int flag = mat[minElem][j];
                if (flag == 0 || visited[j])
                    continue;
                if (distance[j] > flag) {
                    distance[j] = distance[minElem] + flag;
                }
            }
        }

        for (int k = 0; k < V; k++) {
            System.out.println(k + " " + distance[k]);
        }
    }

    static int findMinElem(int arr[], boolean[] visited) {
        int minIndex = -1;
        int temp = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (temp > arr[i] && !visited[i]) {
                temp = arr[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

}
