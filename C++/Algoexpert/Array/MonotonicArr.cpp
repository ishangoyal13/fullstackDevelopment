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
bool solve1(vi &a)
{
	int n = a.size();
	if (n <= 2)
		return true;

	bool nonInc = true, nonDec = true;
	int i = 1;
	while (i < n && (nonInc || nonDec))
	{
		if (a[i] > a[i - 1])
			nonInc = false;
		else if (a[i] < a[i - 1])
			nonDec = false;
		i++;
	}
	return nonInc || nonDec;
}

int main()
{
	vi v{1, 1, 1, 1, 2, 2, 4, 6, 3}, t{10, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 2};
	cout << solve1(t);
}