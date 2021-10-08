#include <bits/stdc++.h>
using namespace std;
 

int minCost(int A[], int n)
{
    int cost = 0;

    sort(A, A + n);

    int K = A[n / 2];

    for (int i = 0; i < n; ++i)
        cost += abs(A[i] - K);

    if (n % 2 == 0) {
        int tempCost = 0;
 
        K = A[(n / 2) - 1];

        for (int i = 0; i < n; ++i)
            tempCost += abs(A[i] - K);
 
        cost = min(cost, tempCost);
    }
 
  
    return cost;
}
 

int main()
{
    int A[] = { 1, 6, 7, 10 };
 
    int n = sizeof(A) / sizeof(A[0]);
 
    cout << minCost(A, n);
 
    return 0;
}