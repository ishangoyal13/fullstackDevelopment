#include <iostream>
using namespace std;

#define endl "\n"
 
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

//Optimised Bubble sort
void bubbleSort(int arr[], int n)
{
    int swp;
    for (int i = 0; i < n-1; i++)
    {
        //to check if any swap happens in the given iteration
        swp = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swp++;
            }
        }
        if(swp == 0)
            return;
    }
    return;
}

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout<< arr[i] << " ";
    cout<< endl;
}
 
// Driver code
int main()
{
    int arr[] = {23, 90, 11, 12, 34, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    print(arr, n);
    return 0;
}