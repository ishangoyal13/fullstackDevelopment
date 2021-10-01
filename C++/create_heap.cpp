#include<iostream>
using namespace std;

void insertMax(int A[],int index)
{
   int temp=A[index];
   int i=index;

   while(temp>A[i/2] && i>1)
   {
       A[i]=A[i/2];
       i=i/2;
   }
   A[i]=temp;
}

void Delete(int A[], int n)
{
    int temp = A[1];
    int i,j;
    i=1,j=2*i;
    int x=A[n-1];
    A[1] = x;

    while(j<n-1)
    {
        if(A[j+1] > A[j])
        {
             j=j+1;
        }

        if(x < A[j])
        {
            swap(A[i],A[j]);
            i=j;
            j=2*j;
        }
        else
        {
            break;
        }
    }

    A[n-1]=temp;
}

int main()
{
    int A[]={0,10,20,30,25,50,40,35};
    for(int i=1;i<=7;i++)
    {
        insertMax(A,i);
    }

    for(int i=1;i<=7;i++)
    {
        cout<<A[i]<<" ";
        
    }
    cout<<endl;
    
    int j=7;
    int n=8;
    while(j>0)
    {
      Delete(A,n--);
      j--;
    } 

    for(int i=1;i<=7;i++)
    {
        cout<<A[i]<<" ";
    }
}
