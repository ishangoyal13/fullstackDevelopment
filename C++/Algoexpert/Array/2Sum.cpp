#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>

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

//Time: O(nlogn) | Space: O(1)
void solve1(vi &v, int &k)
{
	auto l = v.begin(), r = v.end() - 1;
	sort(l, r + 1);
	print(v);
	while (l < r)
	{
		if (*l + *r == k)
		{
			cout << *l << ", " << *r << endl;
			l++, r--;
		}
		else if (*l + *r > k)
			r--;
		else
			l++;
	}
}

//Time: O(n) | Space: O(n)
void solve2(const vi &v, int &k)
{
	// unordered_multiset<int> s;
	unordered_set<int> s;
	bool found = false;
	for (auto &x : v)
	{
		// print(s);
		if (s.find(k - x) == s.end())
			s.emplace(x);
		else
		{
			cout << x << ", " << k - x << endl;
			found = true;
			// return;
		}
	}
	if (!found)
		cout << "Not Found\n";

	print(v);
	print(s);
}

vi solve3(const vi &v, int &k)
{
	int i = 0;
	vector<pair<int, int>> mp(v.size());
	for (auto &x : v)
		mp[i] = {i, x}, i++;

	// for(auto &x : mp)
	// 	cout << x.F << " " << x.S << endl;

	sort(mp.begin(), mp.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });

	int l = 0, r = v.size() - 1;
	while (l < r)
	{
		if (mp[l].S + mp[r].S == k)
			break;
		else if (mp[l].S + mp[r].S > k)
			r--;
		else
			l++;
	}
	return {mp[l].F, mp[r].F};
}

int main()
{
	vi v{4, 5, 3, 7, 1, 2, 8, 7, 2, 7, 0, 21, 4, 32}, t{3, 2, 4};
	int k = 6;

	// solve2(v, k);
	print(solve3(t, k));
	// solve2(t, k);
}