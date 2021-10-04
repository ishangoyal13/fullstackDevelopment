#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

#define FOR(i, start, end, inc) for (##i = start; end > start ? ##i <= end : ##i >= end;##i += inc)
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

const int mod = 1'000'000'007;
const int N = 3e5;

void operator+=(vi &a, const vi &b)
{
	int n = a.size(), m = b.size();
	if (n != m)
		throw exception("Unequal Size Vectors");
	for (int i = 0; i < n; ++i)
		a[i] += b[i];
}

void operator-=(vi &a, const vi &b)
{
	int n = a.size(), m = b.size();
	if (n != m)
		throw exception("Unequal Size Vectors");
	for (int i = 0; i < n; ++i)
		a[i] -= b[i];
}

void operator*=(vi &a, int c)
{
	for (auto &x : a)
		x *= c;
}

void print(const vi &v)
{
	cout << endl;
	for (auto &x : v)
	{
		cout << x << " ";
	}

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

//Time: O(n*m) | Space: O(1)
void solve1(const vvi &a)
{
	int n = a.size(), m = a[0].size();
	if (n * m <= 0)
		return;
	cout << a[0][0] << " ";
	if (n * m <= 1)
		return;
	vi dir = {0, 0}, curr = {0, 0}, diag = {-1, 1};

	while (1)
	{
		if (curr[0] == n - 1) //in last row
			dir = {0, 1};
		else if (curr[1] == 0) //in first col
			dir = {1, 0};
		else if (curr[1] == m - 1) //in last col
			dir = {1, 0};
		else if (curr[0] == 0) //in first row
			dir = {0, 1};
		curr += dir;
		// print(curr);
		if (curr[0] > n - 1 || curr[1] > m - 1)
			break;
		int c = curr[0] + curr[1] + 1, mn = min(n, m);
		c = c > mn ? 2 * mn - c : c;

		while (c--)
		{
			cout << a[curr[0]][curr[1]] << " ";
			curr += diag;
		}
		curr -= diag;
		// cout << " (" << a[curr[0]][curr[1]] << ") ";

		diag *= -1;
	}
}

void solve2(vvi &a)
{
	//solve using algoexpert method
}

int main()
{
	vvi a{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	vvi b{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	solve1(vvi{{1, 2, 3}});
}