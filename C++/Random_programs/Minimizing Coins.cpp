/*Consider a money system consisting of n coins. 
Each coin has a positive integer value. 
Your task is to produce a sum of money x using 
the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, 
an optimal solution is 5+5+1 which requires 3 coins.*/
#include <bits/stdc++.h>
using namespace std;
 
#define lli long long int
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        int n,x,coins;cin>>n>>x;
        std::vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        std::vector<int> dp(x+1,1e9);
        dp[0]=0;
        for(int i=1;i<x+1;i++){
            for(int j=0;j<n;j++){
                if(i-v[j]>=0)dp[i]=min(dp[i],1+dp[i-v[j]]);
            }
        }
        cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
    }
}
