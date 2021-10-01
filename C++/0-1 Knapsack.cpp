#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<int>& v, vector<int>& w, int W, int i, int sum)
{
	if(W < 0)
		return 0;
	
	if(i == v.size() || W == 0)
	{
		return sum;
	}
	
	if(dp[W][i] != -1)
	{
		return dp[W][i];
	}
	
	dp[W][i] = max(find(v, w, W, i + 1, sum), find(v, w, W - w[i], i + 1, sum + v[i]));
	return dp[W][i];
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n, 0);
	vector<int> w(n, 0);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	for(int i = 0; i < n; i++)
		cin >> w[i];
		
	int W;
	cin >> W;
	
	cout << find(v, w, W, 0, 0);
		
}
