#include <iostream>
#include <climits>
#define int long long
using namespace std;


// Memoization Helper
int minSteps_help(int n, int *dp){
	// Base Case
	if(n<=1)
		return 0;

	// Check if already exists
	if(dp[n] != -1)
		return dp[n];

	int y= INT_MAX, z = INT_MAX;
	int x = minSteps_help(n-1,dp);

	if(n%2 ==0)
		y = minSteps_help(n/2,dp);
	if(n%3 == 0)
		z = minSteps_help(n/3,dp);

	int output = min(x,min(y,z)) + 1;

	dp[n] = output;

	return output;
}	


// Memoization main
int minSteps_memoization(int n){
	int * dp = new int[n+1];
	for(int i = 0;i<=n;i++){
		dp[i] = -1;
	}
	int res = minSteps_help(n,dp);
	delete [] dp;
	return res;
}

// Naive Approach
int minSteps(int n){
	if(n<=1)
		return 0;    
	int x = minSteps(n-1);
	int y = INT_MAX;
	int z = INT_MAX;
	if(n%2 == 0)
		y = minSteps(n/2);
	if(n%3 == 0)
		z = minSteps(n/3);

	int ans = min(x,min(y,z)) + 1;

	return ans;
}

// Main Driver Code
int32_t main() {
	int n;
	cin >> n;
	cout << minSteps_memoization(n)<< endl;
	return 0;
}
