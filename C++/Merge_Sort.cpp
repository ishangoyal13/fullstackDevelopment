#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int left, int mid, int right)
{
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    int b[n1];
    int c[n2];

    for (int i = 0; i < n1; i++)
    {
        b[i] = a[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        c[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (b[i] < c[j])
        {
            a[k] = b[i];
            i++;
            k++;
        }
        else
        {
            a[k] = c[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        a[k] = b[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
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

    mergeSort(a, 0, n - 1);

    cout << "Sorted Array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}