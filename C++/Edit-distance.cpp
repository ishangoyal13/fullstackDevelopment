#include<bits/stdc++.h>
using namespace std;

int main(){
       string s,t;
       cin>>s>>t;
       s='0'+s;
       t='0'+t;
       int n=s.size()-1;
       int m=t.size()-1;
       int dp[n+1][m+1];
       dp[0][0]=0;
       for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
             if(i==0)dp[i][j]=j;
             else if(j==0)dp[i][j]=i;
             else{
                if(s[i]==t[j]){
                    dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]));
                }
                else dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
              }
          }
       }
       cout<<dp[n][m]<<endl;
}
