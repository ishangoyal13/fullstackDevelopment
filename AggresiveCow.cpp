#include<iostream>
#include<algorithm>
using namespace std;


bool checkCOWS(int A[], int size, int c, int mid)
{
	int pos_prev = A[0];
	int count = 1;
	for (int i = 1; i < size; i++)
	{
		if (A[i] - pos_prev >= mid)
		{
			pos_prev = A[i];
			count++;
			if (count == c)
			{
				return true;
			}
		}
	}
	return false;
}

int correctPlace(int A[], int size, int c)
{
	int f = 0, l = A[size - 1] - A[0];

	int ans = -1;
	while (f <= l)
	{
		int mid = (f + l) / 2;
		if (checkCOWS(A, size, c, mid))
		{
			ans = mid;
			f = mid + 1;
		}
		else
		{
			l = mid - 1;
		}
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int n, c;
		cin >> n >> c;
		int A[n] = {0};
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		sort(A, A + n);
		cout << correctPlace(A, n, c) << endl;
	}


}
