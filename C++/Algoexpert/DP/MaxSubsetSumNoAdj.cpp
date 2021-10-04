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

void solve1(vi &v)
{
	int n = v.size();
	vi ans(n, 0);
	ans[0] = v[0], ans[1] = max(v[1], ans[0]);
	for(int i=2; i<n; ++i)
	{
		ans[i] = max(ans[i-1], v[i] + ans[i-2]);
	}
	// print(ans);
	cout << "Max sum no adjacent: " << ans[n-1];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vi v{7, 10, 12, 7, 9, 14};
	solve1(v);
}