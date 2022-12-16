#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>

using namespace std;

#pragma region DEFINES
#define FOR(i, start, end, inc) for (##i = start;##i < end;##i += inc)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define PB push_back
#define MP make_pair
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

const int mod = 1'000'000'007;
const int N = 3e5;

#pragma endregion

template <class T>
void print(const T &v)
{
	for (auto &x : v)
		cout << x << " ";
	cout << endl;
}

void print(const vvi &v)
{
	for (auto &x : v)
	{
		for (auto &y : x)
			cout << y << " ";
		cout << endl;
	}
}

//Time: O(n^2) | Space: O(n)
void solve1(const vi &a)
{
	int n = a.size(), ans = a[0], maxInd = 0;
	vector<int> dp(a);
	vector<int> seq(n, -1);
	dp[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[i] > a[j] && dp[i] <= a[i] + dp[j])
			{
				dp[i] = a[i] + dp[j];
				seq[i] = j;
			}
		}
		if (dp[maxInd] <= dp[i])
			maxInd = i;
	}
	// print(seq);
	// deb(maxInd);
	ans = dp[maxInd];
	int ind = n - 1;
	for (int i = maxInd; i >= 0;)
	{
		// dp[ind--] = a[i];
		dp[ind--] = i;
		if (!i || i == -1)
			break;
		else
			i = seq[i];
	}
	for (int i = ind + 1; i < n; ++i)
		cout << dp[i] << " ";
	cout << endl
		 << "Max Sum: " << ans;
}

int main()

{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vi a{1, 101, 2, 3, 100},	  //106
		b{8, 12, 2, 3, 15, 5, 7}; //35
	solve1(b);
}