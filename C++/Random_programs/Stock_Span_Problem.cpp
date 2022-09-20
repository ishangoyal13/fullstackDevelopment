#include<bits/stdc++.h>
using namespace std;

void fun(int A[],int n)
{
	stack<int> s;
	s.push(A[0]);
	cout<<"-1"<<" ";
	
	for(int i=1;i<n;i++)
	{
		while(s.empty()==false&&A[i]>=s.top())
		 s.pop();
		
		s.empty()==true?cout<<"-1"<<" ":cout<<s.top()<<" ";
		
		s.push(A[i]);
	}
}

int main()
{
	int n;
	cout<<"Enter the number of days ";
	cin>>n;
	int A[n];
	cout<<"Enter the price of the stock ";
	for(int i=0;i<n;i++)
	 cin>>A[i];
	fun(A,n);
	return 0;
}
