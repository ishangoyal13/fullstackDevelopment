#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int temp = arr[n-1];
        int ans[n] = {0};

        for(int i=n-1;i>=0;i--){
            if(temp!=0 || arr[i]!=0){
                ans[i] = 1;
                temp = max(temp,arr[i]);
                temp--;
            }
            else{
                temp = arr[i];
            }
        }

        for(int i=0;i<n;i++){
            cout<<aans[i]<<" ";
        }
        cout<<endl;
    }
}