#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    vector<long> v1;
	    for(ll i=0;i<n;i++){
	        ll ele;
	        cin>>ele;
	        v1.push_back(ele);
	    }
	    
	    vector<long> v2;
	    v2 = v1
	    for(ll i=0;i<k-1;i++){
	        copy(v1.begin(),v1.end(),back_inserter(v2));
	    }
	    
	    ll x1 = INT_MIN;
	    ll x2 = 0;

	    for(ll i=0;i<v2.size();i++){
	        x2 = x2 + v2[i];
            if(x1 < x2){
                x1 = x2;
            }	       
            
            if(x2<0){
                x2 = 0;
            }
	    }
	    cout<<x1<<endl;
	    
	}
	return 0;
}


// GIVES TLE...OPTIMIZING..