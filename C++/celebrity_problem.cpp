#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        //M1: N^2time and N space approach: Using indegree and outdegree
    //   int indegree[n];
    //   int outdegree[n];
    //   for(int i=0;i<n;i++)
    //   {
    //       for(int j=0;j<n;j++)
    //       {
    //           if(M[i][j]==1)
    //           {
    //               indegree[j]++;
    //               outdegree[i]++;
    //           }
    //       }
    //   }
    //   for(int i=0;i<n;i++)
    //   {
    //       if(indegree[i]==n-1 && outdegree[i]==0)
    //             return i;
    //   }
    //   return -1;
    
    
    //M2: Linear Time : Using Stack : N time and space
        // stack<int> stk;
        // for(int i=0;i<n;i++)
        //     stk.push(i);
        // while(stk.size()>1)
        // {
        //     int a= stk.top();
        //     stk.pop();
        //     int b= stk.top();
        //     stk.pop();
        //     if(M[a][b]==1)
        //         stk.push(b);
        //     else
        //         stk.push(a);
        // }
        // //Rechecking
        // int cel=stk.top();
        // for(int i=0;i<n;i++)
        //     if(i!=cel && (M[cel][i]==1 || M[i][cel]==0))
        //         return -1;
        // return cel;
        
        
        
    //M3: N time and constant Space: Two Pointers
        int low=0;
        int high=n-1;
        while(low<high)
        {
            if(M[low][high]==1)
                low++;
            else
                high--;
        }
        int cel=low;
        for(int i=0;i<n;i++)
            if(i!=cel && (M[cel][i]==1 || M[i][cel]==0))
                return -1;
        return cel;
        
        
    
    }
};



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}