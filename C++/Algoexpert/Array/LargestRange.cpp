#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <unordered_map>

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

void print(const vi &v)
{
	for (auto &x : v)
		cout << x << " ";
	cout << endl;
}

//Time: O(n) | Space: O(n)
int solve1(vi &a)
{
	unordered_map<int, bool> mp;
	int n = a.size(), len = 1;
	if (n <= 1)
		return n;
	for (auto &x : a)
		mp[x] = true;
	for (int i = 0; i < n; ++i)
	{
		if (mp[a[i]])
		{
			mp[a[i]] = false;
			int t = a[i] - 1, count = 1;
			while (mp[t])
				mp[t] = false, ++count, --t;
			t = a[i] + 1;
			while (mp[t])
				mp[t] = false, ++count, ++t;
			len = max(len, count);
			// n -= count;
		}
	}
	return len;
}

int main()
{
	vi v{1, 2, 3, 4};
	cout << solve1(v);
}