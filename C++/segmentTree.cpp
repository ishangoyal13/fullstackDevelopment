#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000
int a[SIZE], seg[4*SIZE];
void buildSeg(int s, int low, int high){
    if(low==high){
        seg[s]=a[low];
        return;
    }
    int mid = (low + high)/2;
    buildSeg(2*s+1,low, mid);
    buildSeg(2*s+2,mid+1,high);
    seg[s]= __gcd(seg[2*s+1],seg[2*s+2]);
}
int query(int ind,int low, int high, int ql, int qr){
    if(low>=ql && high <= qr)return seg[ind];
    if(high<ql || low >qr)return 0;
    int mid = (low+high)/2;
    int left = query(2*ind+1, low, mid, ql, qr);
    int right = query(2*ind+2, mid+1, high, ql, qr);
    return __gcd(left, right);
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    buildSeg(0,0,n-1);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l<0 || r > n-1) cout << -1 <<endl;
        else cout <<query(0,0,n-1,l,r)<<endl;;
    }
    return 0; 
}
