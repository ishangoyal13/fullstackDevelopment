//To find out the max and min element of an array with lowest number of comparisons.
//There are techniques like linear search and all where you take one element at a time and compare with the other
// Best method is to compare in pairs.
//If n is even it takes 1+3*(n-2)/2 comparisons
//If n is odd it takes 3*(n-1)/2   comparisons


#include <bits/stdc++.h>
using namespace std;

int getminmax(int arr[], int n)
{
    int max, min, i;

    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            max = arr[0];
            min = arr[1];
        }
        else
        {
            max = arr[0];
            min = arr[1];
        }
        i = 2;
    }
    else
    {
        max = 0;
        min = arr[0];
        i = 1;
    }

    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > max)
                max = arr[i];

            if (arr[i + 1] < min)
                min = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > max)
                max = arr[i + 1];

            if (arr[i] < min)
                min = arr[i];
        }
        i += 2;
    }

    cout<<"Max is : "<<max<<" and min is: "<<min;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    getminmax(arr, n);
    return 0;
}