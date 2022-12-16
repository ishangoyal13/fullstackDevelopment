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

//Time: O(n) | Space: O(1)
void solve1(vi &a)
{
	int n = a.size();
	int lg = 0;

	for (int i = 1; i <= n - 2; ++i)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) //peak
		{
			int count = 1, p = i;
			--i;
			//Left
			while (i >= 0 && a[i] < a[i + 1])
				--i, ++count;
			//Right
			i = p + 1;
			while (i <= n - 1 && a[i] < a[i - 1])
				++i, ++count;
			lg = max(lg, count);
			--i;
		}
	}
	cout << lg;
}

int main()
{
	vi a{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
	solve1(a);
}