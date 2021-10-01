#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i=0, j=0, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    selectionSort(a, n);

    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
