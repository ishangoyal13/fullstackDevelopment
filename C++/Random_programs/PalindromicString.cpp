#include<bits/stdc++.h>
using namespace std;

int ispalindromic(string &s)
{
    int n = s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i] != s[n-i-1])
            return 0;
    }
    return 1;
}
int main()
{
    string s;
    cout<<"Enter the string";
    cin>>s;
    int result;
    result = ispalindromic(s);
    if(result == 1)
        cout<<"It is a Palindrome";
    else
        cout<<"It is not a Palindrome";
    return 0;
}
