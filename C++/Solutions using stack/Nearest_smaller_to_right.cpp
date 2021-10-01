// Nearest smaller to the right

#include<iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {1,3,2,4}; // ans - -1 2 -1 -1
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> v;
	stack<int> s;

	for(int i=n-1; i>=0 ; i++){
		if(s.size()==0)
			v.push_back(-1);

		else if(s.size()>0 && s.top()>arr[i])
			v.push_back(s.top());

		else if(s.size()>0 && s.top()>=arr[i]){
			while(s.size()>0 && s.top()>=arr[i])
				s.pop();

			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
 	reverse(v.begin(), v.end());

	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	

	return 0;
}
