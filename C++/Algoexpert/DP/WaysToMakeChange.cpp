#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

void solve1(vi &coins, int sum)
{
	int n = coins.size();
	vvi ways(n + 1, vi(sum + 1, 0));
	for (int c = 0; c <= n; ++c)
		ways[c][0] = 1;

	// for (int c = 1; c <= n; ++c)
	// 	for (int amt = 1; amt <= sum; ++amt)
	// 	{
	// 		int include = ways[c][amt - coins[c - 1]];
	// 		int exclude = ways[c - 1][amt];
	// 		if (amt >= coins[c - 1])
	// 			ways[c][amt] = include + exclude;
	// 		else
	// 			ways[c][amt] = exclude;
	// 	}

	for (int amt = 1; amt <= sum; ++amt)
		for (int c = 1; c <= n; ++c)
		{
			int include = ways[c][amt - coins[c - 1]];
			int exclude = ways[c - 1][amt];
			if (amt >= coins[c - 1])
				ways[c][amt] = include + exclude;
			else
				ways[c][amt] = exclude;
		}

	print(ways);
	cout << ways[n][sum];
}

void solve2(vi &coins, int sum)
{
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vi v;
	// v = {1, 5, 10, 25};
	// solve1(v, 10); //should be 4

	v = {1, 2, 5};
	solve1(v, 5); //should be 4
}