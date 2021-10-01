#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}


void rotate(int A[], int n)
{
    int i=0;
    int j=n-2;
    while(i<=j)
    {
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i++;
        j--;
    }
    
    i=0;
    j=n-1;
    while(i<=j)
    {
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i++;
        j--;
    }
}
