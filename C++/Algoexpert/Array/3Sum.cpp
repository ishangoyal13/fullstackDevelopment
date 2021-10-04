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

//Time: O(n^2) | Space: O(1)
void solve1(vi &v, int &k)
{
	sortall(v);
	// unique(all(v));
	int i, n = v.size();
	FOR(i, 1, n - 3, 1)
	{
		auto l = v.begin() + i + 1, r = v.end() - 1;
		while (l < r)
		{
			if (*l + *r == k - v[i])
			{
				cout << *l << ", " << *r << ", " << v[i] << endl;
				l++, r--;
			}
			else if (*l + *r > k - v[i])
				r--;
			else
				l++;
		}
	}
}

int main()
{
	vi v{4, 5, 3, 7, 1, 2, 8, 7, 2, 7, 0, 21, 4, 32};
	int k = 9;
	solve1(v, k);
}