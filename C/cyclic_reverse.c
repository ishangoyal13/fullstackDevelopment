#include <stdio.h>
#include <stdlib.h>

int cyclic_shift(int n,int arr[])
{
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[n] = arr[n - 1];
    }
}

int main()
{
    int n,i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        cyclic_shift(n, arr);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}