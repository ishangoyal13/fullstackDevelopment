#include<bits/stdc++.h>
using namespace std;
int sortEvenOdd(int arr[],int n){
    int even = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            swap(arr[i],arr[even]);
            even++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortEvenOdd(arr,n);
}
