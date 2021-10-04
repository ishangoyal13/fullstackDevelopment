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

//https://leetcode.com/problems/container-with-most-water/submissions/
//Time: O(n) | Space: O(1)
void solve1(vi &hist)
{
	int n = hist.size();
	if (n < 2)
	{
		// return 0;
		cout << 0 << endl;
		return;
	}
	int i = 0, j = n - 1;
	int maxArea = 0;
	while (i < j)
	{
		int height = min(hist[i], hist[j]);
		int width = j - i;
		int water = height * width;
		maxArea = max(maxArea, water);
		if (hist[i] < hist[j])
			++i;
		else
			--j;
	}
	// return maxArea;
	cout << maxArea << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vi h{1, 8, 6, 2, 5, 4, 8, 3, 7};
	solve1(h);
}