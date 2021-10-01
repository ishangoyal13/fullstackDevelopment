#include <iostream>
#include <string>
using namespace std;

//Time : O(n) | Space : O(1)
bool isPal(const string &s)
{
	for (int i = 0, n = s.size(); i < n / 2; ++i)
		if (s[i] != s[n - 1 - i])
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s);
	cout << isPal(s);
}