#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define FOR(i, start, end, inc) for (##i = start;##i <= end;##i += inc)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = (a).begin(); it != (a).end(); it++)
#define PI 3.14159f
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef unordered_set<int> usi;

const int mod = 1'000'000'007;
const int N = 3e5;

void print(const vi &v)
{
	for (auto &x : v)
		cout << x << " ";
	cout << endl;
}

//Naive
void bruteForce()
{
	vector<int> a = {-1, 2, 4, -3, 5, 2, -5, 2};
	int n = a.size();
	int maxSum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			//Current Subarray is: A[i..j]
			int currSum = 0;
			for (int k = i; k <= j; ++k)
				currSum += a[k];
			maxSum = max(maxSum, currSum);
		}
	}
	cout << maxSum;
}

void optimizedBruteForce()
{
	vector<int> a = {-1, 2, 4, -3, 5, 2, -5, 2};
	int n = a.size();
	int maxSum = 0;
	for (int i = 0; i < n; ++i)
	{
		int currSum = 0;
		for (int j = i; j < n; ++j)
		{
			//Current Subarray is: A[i..j]
			currSum += a[j];
			maxSum = max(maxSum, currSum);
		}
	}
	cout << maxSum;
}

void solve2()
{
	//This is for subsequence not subarray
	int a[] = {-1, 2, 4, -3, 5, 2, -5, 2}, n = sizeof(a) / sizeof(*a);
	int sum = 0, best = INT_MIN;
	for (auto i = 0; i < n; ++i)
	{
		sum = max(sum, a[i] + sum);
		best = max(best, sum);
	}
	cout << best << endl;
}

//Time: O(n) | Space: O(1)
//https://quanticdev.com/algorithms/dynamic-programming/kadanes-algorithm/
void solve1()
{
	vector<int> a = {-1, 2, 4, -3, 5, 2, -5, 2};
	int n = a.size();
	int sum = 0, best = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		sum = max(a[i], a[i] + sum);
		best = max(best, sum);
	}
	cout << best << endl;
}

int main()
{
	solve1();
	//solve2();
	bruteForce();
	cout << endl;
	optimizedBruteForce();
}