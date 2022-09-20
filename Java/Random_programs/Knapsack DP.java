
public class Knapsack {
     static int dp[][] = new int[102][1002];

     static int knapsack(int wt[], int val[], int w, int n){
         if(n==0 || w==0)
             return 0;
         if(dp[n][w]!=-1)
             return dp[n][w];

         if(wt[n-1]<=w)
             return dp[n][w] = Math.max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1),knapsack(wt, val, w, n-1));
         else
             return dp[n][w] = knapsack(wt, val, w, n-1);
     }
    public static void main(String args[]){
        int wt[]={1,3,4,5};
        int val[]={1,4,5,7};
        int w = 10;
        int n = 4;
        System.out.println(knapsack( wt, val, w, n));

        }
    }

