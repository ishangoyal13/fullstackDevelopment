#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

#define FOR(i, start, end, inc) for (##i = start; end > start ? ##i <= end : ##i >= end;##i += inc)
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

void print(const vvi &v)
{
	for (auto &x : v)
	{
		for (auto &y : x)
			cout << y << " ";
		cout << endl;
	}
}

//Iterative
//Time: O(n*m) | Space: O(1)
void solve1(const vvi &a)
{
	int sR = 0, sC = 0, eR = a.size() - 1, eC = a[0].size() - 1;

	while (sR <= eR && sC <= eC)
	{
		cout << "\nRows: " << sR << " -> " << eR << endl;
		cout << "Cols: " << sC << " -> " << eC << endl;
		if (eR - sR + 1 == 1)
		{
			for (int i = sC; i <= eC; ++i)
				cout << a[sR][i] << " ";
			return;
		}
		if (eC - sC + 1 == 1)
		{
			for (int i = sR; i <= eR; ++i)
				cout << a[i][sC] << " ";
			return;
		}
		for (int i = sC; i <= eC; ++i)
			cout << a[sR][i] << " ";
		for (int i = sR + 1; i <= eR; ++i)
			cout << a[i][eC] << " ";
		for (int i = eC - 1; i >= sC; --i)
			cout << a[eR][i] << " ";
		for (int i = eR - 1; i >= sR + 1; --i)
			cout << a[i][sC] << " ";
		--eC, --eR, ++sC, ++sR;
		cout << "\nRows: " << sR << " -> " << eR << endl;
		cout << "Cols: " << sC << " -> " << eC << endl;
		cout << endl << endl;
	}
}

//Recursive
void solve2(vvi &a, int sR, int sC, int eR, int eC)
{
	if (eR - sR + 1 == 1)
	{
		for (int i = sC; i <= eC; ++i)
			cout << a[0][i] << " ";
		return;
	}
	if (eC - sC + 1 == 1)
	{
		for (int i = sR; i <= eR; ++i)
			cout << a[i][0] << " ";
		return;
	}
	for (int i = sC; i <= eC; ++i)
		cout << a[sR][i] << " ";
	for (int i = sR + 1; i <= eR; ++i)
		cout << a[i][eC] << " ";
	for (int i = eC - 1; i >= sC; --i)
		cout << a[eR][i] << " ";
	for (int i = eR - 1; i >= sR + 1; --i)
		cout << a[i][sC] << " ";

	solve2(a, sR + 1, sC + 1, eR - 1, eC - 1);
}

int main()
{
	vvi v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int n = v.size(), m = v[0].size();
	solve1(v);
}