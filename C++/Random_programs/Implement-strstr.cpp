#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

int strstr(string s, string x)
{
     
     int a = s.length();
     int b = x.length();
     
     if(b==0 || a==0&&b==0){
         return -1;
     }
     
     for(int i=0;i<a;i++){
         if(s[i]==x[0]){
             int temp = i;
             int j =0;
         
         while(temp<a && j<b){
             if(s[temp]!=x[j]){
                 break;
             }
             
             temp++;
             j++;
             
         }
         
         if(j==b) {
             return i;
         }
         }
         
         
     }
     
     return -1;
}