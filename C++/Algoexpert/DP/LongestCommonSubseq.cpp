#include <iostream>
#include <vector>
#include <algorithm>

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

//Time: O(n*m) | Space: O(n*m)
void solve1(string &a, string &b)
{
	int n = a.size(), m = b.size();
	vvi dp(n + 1, vi(m + 1, 0));
	
	//order of for loops doesnt matter
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[n][m] << endl;
	// print(dp);
}

//Time: O(n*m) | Space: O(min(n, m))
int solve2(string &a, string &b)
{
	int n = a.size(), m = b.size();
	if(n == 0) return m;
	if (m == 0) return n;
	if (n != std::min(n, m))
	{
		swap(a, b);
		swap(n, m);
	}

	vi curr(n + 1, 0), prev(n + 1, 0);

	//order of for loops matter
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= m; ++i)
		{
			if (a[i - 1] == b[j - 1])
				curr[i] = prev[i - 1] + 1;
			else
				curr[i] = max(curr[i - 1], prev[i]);
		}
		prev.swap(curr);
	}
	// print(prev), print(curr);
	cout << prev[n] << endl;
}

int main()

{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// string a = "zxvvyzw", b = "xkykzpw";
	string a = "aab", b = "abc";
	solve1(a, b);
	solve2(a, b);
	cout << endl << endl;
}