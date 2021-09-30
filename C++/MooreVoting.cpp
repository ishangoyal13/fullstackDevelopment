//This is used to find the majority element in the array
//The majority element is the one which will be present more than (n/2) times.
// Link to the question: https://leetcode.com/problems/majority-element/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }
    else
    {
        int count = 1, el = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == el)
            {
                count = count + 1;
            }
            else
            {
                count = count - 1;
            }

            if (count == 0)
            {
                el = arr[i];
                count = 1;
            }
        }

        cout << el;
    }

    return 0;
}
