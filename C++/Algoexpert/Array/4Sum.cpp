#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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
// typedef unordered_set<int> usi;

const int mod = 1'000'000'007;
const int N = 3e5;

void print(const vi &v)
{
	for (auto &x : v)
		cout << x << " ";
	cout << endl;
}

//Time: O(n^3logn) | Space: O()
vvi solve1(vi &v, int &k)
{
	vvi res;
	int n = v.size();
	if (n <= 3)
		return vvi(all(res));
	sortall(v); //nlogn
	int i, j;
	FOR(i, 0, n - 4, 0) //n
	{
		FOR(j, i + 1, n - 3, 0) //n
		{
			int l = j + 1, r = n - 1;

			while (l < r) //n
			{
				if (v[l] + v[r] == k - v[i] - v[j])
				{
					res.emplace_back(vi{v[i], v[j], v[l], v[r]});
					int d = v[l++];

					while (l < r && v[l] == d)
						++l;

					d = v[r--];
					while (l < r && v[r] == d)
						--r;
				}
				else if (v[l] + v[r] > k - v[i] - v[j])
					r--;
				else
					l++;
			}
			int d = v[j++];
			while (j < n - 2 && v[j] == d)
				++j;
		}
		int d = v[i++];
		while (i < n - 3 && v[i] == d)
			++i;
	}
	return res;
}

int main()
{
	vi v{1, 0, -1, 0, -2, 2};
	int k = 0;
	auto res = solve1(v, k);
	for (auto &x : res)
		print(x);

	// vi a{1, 2}, b{1, 2};
	// cout << (a == b);
}