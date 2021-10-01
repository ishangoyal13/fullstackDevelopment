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

//Time: O(m log m + n log n) | Space: O(1)
void solve1(vi &a, vi &b)
{
	sortall(a);
	sortall(b);
	print(a);
	print(b);
	auto p1 = a.begin(), p2 = b.begin();
	int diff = INT_MAX, v1 = -1, v2 = -1;
	while (p1 != a.end() && p2 != b.end())
	{
		// cout << *p1 << ", " << *p2 << endl;
		if (abs(*p1 - *p2) >= diff)
		{
			p1++, p2++;
			continue;
		}

		diff = abs(*p1 - *p2), v1 = *p1, v2 = *p2;
		if (diff == 0)
			break;
		v1 < v2 ? p1++ : p2++;
	}
	cout << v1 << ", " << v2 << " -> Diff: " << diff << endl;
}

int main()
{
	vi a{1, 3, 15, 11, 2}, b{23, 127, 235, 19, 8};
	solve1(a, b);
}