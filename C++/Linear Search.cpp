#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    int res = search(arr, n, x);
    (res == -1)
        ? cout << "Element is not present in the array"
        : cout << "Element is present at index " << res;
    return 0;
}