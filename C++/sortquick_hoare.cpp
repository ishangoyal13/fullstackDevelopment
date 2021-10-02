#include<bits/stdc++.h>
using namespace std;

int low(int a[],int l,int r)
{
    int pivot=a[l],i=l-1,j=r+1;
    while(true)
    {
        do
        {
            i++;
        }while(a[i]<pivot);

        do
        {
            j--;
        }while(a[j]>pivot);

        if(i>=j) return j;
        a[i]=a[i]^a[j]^(a[j]=a[i]);
    }
}

int high(int a[],int l,int r)
{
    int pivot=a[r],i=l,j=r;
    while(i<j)
    {
        while(i<=r && a[i]<pivot) i++;
        while(j>=0 && a[j]>pivot) j--;
        if(i>=j) return i-1;
        a[i]=a[i]^a[j]^(a[j]=a[i]);
    }
    return 0;   //this line is never reached
}

int mid(int a[],int l,int r)
{
    int pivot=a[(l+r)>>1],i=l-1,j=r+1;
    while(true)
    {
        do
        {
            i++;
        }while(a[i]<pivot);

        do
        {
            j--;
        }while(a[j]>pivot);

        if(i>=j) return j;
        a[i]=a[i]^a[j]^(a[j]=a[i]);
    }
}

void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=low(a,l,r);
        //int p=high(a,l,r);
        //int p=mid(a,l,r);
        quicksort(a,l,p);
        quicksort(a,p+1,r);
    }
}

int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];

    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
