#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arr[100];
    int arr2[100];
    int n, i;
    cin >> n;
    for (i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }
    for (i = n; i >= 0; i--)
    {
        arr2[n - i] = arr[i - 1];
    }
    for (i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}
