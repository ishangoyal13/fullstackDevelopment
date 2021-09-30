#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);

    return i + 1;
}

void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);

        quicksort(a, l, pi - 1);
        quicksort(a, pi + 1, r);
    }
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int *a = new int[n];

    cout << "Enter Array Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);

    cout << "Sorted Array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}