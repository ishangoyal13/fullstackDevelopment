/*
Given two integer arrays sorted in ascending order and the size of the arrays, merge the
two arrays and return the result
Example :

Input: a = [1,2,3], m = 3, b = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

*/
#include <bits/stdc++.h>
using namespace std;
void merge(vector <int> &a , int m , vector <int> &b , int n)
{
    int i = m - 1 , j = n - 1 , idx = m + n - 1;
    while(i >= 0 && j >= 0)
    {
        if(a[i] >= b[j])
        {
            a[idx] = a[i];
            i--;
        }
        else
        {
            a[idx] = b[j];
            j--;
        }
        idx--;
    }
    while(i >= 0)
        a[idx--] = a[i--];
    while(j >= 0)
        a[idx--] = b[j--];
    return;
}
int main()
{
    vector <int> a = {1 , 2 , 3};
    vector <int> b = {2 , 6 , 7};
    int m = 3 , n = 3;
    a.resize(m + n);
    merge(a , m , b , n);
    for(int &x : a)
        cout << x << " ";
    return 0;
}