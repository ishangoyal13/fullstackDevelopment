#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <set>

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

const int mod = 1'000'000'007;
const int N = 3e5;

template <class T>
void print(const T &v)
{
	for (auto &x : v)
		cout << x << " ";
	cout << endl;
}

//Time: O(n) | Space: O(1)
void solve1(vi &v, int &k)
{
	int i = v.size() - 1, j = 0;

	while (j < i)
	{
		while (v[j] != k)
			j++;
		while (v[i] == k)
			i--;
		if (j < i)
			swap(v[j++], v[i--]);
	}

	print(v);
}

//No swaps
void solve2(vi &v, int &k)
{
	int ind = 0, n = v.size();
	for (int i = 0; i < n; ++i)
		if (v[i] != k)
			v[ind++] = v[i];
	while (ind < n)
		v[ind++] = k;
	print(v);
}

int main()
{
	vi v{4, 5, 3, 7, 1, 2, 8, 7, 2, 7, 0, 21, 2, 2}, t{4,1,3,2,2,7,6,2,3,1,2};
	int k = 2;
	solve1(t, k);
	solve2(t, k);
}