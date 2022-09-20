#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

#define float long double
#define double long double
#define ff first
#define ss second
#define pb push_back

#define vi vector<int>

// caluclates S1 *S2
// the ans array stores the answer in reverse format
// i.e ans[0]=units digit ans[1]=ten's digit.
// O(5*N) time for each multiplication
// a string containing the answer in proper format is returned
string multiply(string s1, string s2)
{

    int a[(int)(1e5)], b[(int)(1e5)];
    int l1 = s1.length();
    int l2 = s2.size();
    int i, j, tmp;
    int ans[(int)2e5] = {0};
    for (i = l1 - 1, j = 0; i >= 0; i--, j++)
        a[j] = s1[i] - '0';

    for (i = l2 - 1, j = 0; i >= 0; i--, j++)
        b[j] = s2[i] - '0';

    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < l1; j++)
            ans[i + j] += b[i] * a[j];
    }
    for (i = 0; i < l1 + l2; i++)
    {
        tmp = ans[i] / 10;
        ans[i] = ans[i] % 10;
        ans[i + 1] = ans[i + 1] + tmp;
    }
    for (i = l1 + l2; i >= 0; i--)
        if (ans[i] > 0)
            break;
    string s3;
    for (; i >= 0; i--)
    {
        //printf("%d", ans[i]);
        s3 += (ans[i] + '0');
    }
    return s3;
}
void fact(int n)
{
    string s = "2";
    for (int i = 3; i <= n; i++)
    {

        s = multiply(s, to_string(i));
    }
    cout << s + "\n";
}
signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 0 or n == 1)
        {
            cout << "1\n";
            continue;
        }
        fact(n);
    }

    return 0;
}