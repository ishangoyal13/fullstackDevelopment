#include<iostream>
using namespace std;

//value of n should be even
#define n 8

bool issafe(int a[n][n],int x,int y)
{
    			for(int i=0;i<y;i++)
        			if(a[x][i])   
            				return false;
    			for(int i=x,j=y;i>=0 && j>=0;i--,j--)
        			if(a[i][j])
            				return false;
    			for(int i=x,j=y;j>=0 && i<n;i++,j--)
        			if(a[i][j])
            				return false;
    			return true;
}

bool nqueen(int a[n][n],int y)
{
    			if(y>=n)
        			return true;
    			for(int i=0;i<n;i++)
        			if(issafe(a,i,y))
        			{
            				a[i][y]=1;
            				if(nqueen(a,y+1))
                				return true;
            				a[i][y]=0;
        			}
    			return false;
}

int main()
{
    			int a[n][n];
    			for(int i=0;i<n;i++)
        			for(int j=0;j<n;j++)
            				a[i][j]=0;
    			if(nqueen(a,0)==false)
        			cout<<"queen is not safe anywhere"<<endl;
    			for(int i=0;i<n;i++)
    			{
        			for(int j=0;j<n;j++)
            				cout<<a[i][j]<<" ";
        			cout<<endl;
    			}
    			return 0;
}
