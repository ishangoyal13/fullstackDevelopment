using System;
 
class GFG {

static int minCost(int []A, int n)
{
    
    int cost = 0;
 
    
    Array.Sort(A);
 
    int K = A[n / 2];
 
    
    for (int i = 0; i < n; ++i)
        cost += Math.Abs(A[i] - K);
 
   
    if (n % 2 == 0) {
        int tempCost = 0;
 
        K = A[(n / 2) - 1];
 
        
        for (int i = 0; i < n; ++i)
            tempCost += Math.Abs(A[i] - K);
 
        
        cost = Math.Min(cost, tempCost);
    }
 
    
    return cost;
}
 
public static void Main(String[] args)
{
    int []A = new int []{ 1, 6, 7, 10 };
 
    int n = A.Length;
 
    Console.WriteLine(minCost(A, n));
}
}