#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long i, l,r;
    cin>>l>>r;

    for(i=0;i<l-r+1;i+=2){
        cout<<l+i<<" "<<l+i+1<<endl;
    }
}