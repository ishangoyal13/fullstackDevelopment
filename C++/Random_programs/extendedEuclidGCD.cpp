#include <iostream>
using namespace std;

class Triplet{
public :

	int gcd;
	int x;
	int y;
};

Triplet gcdExtendedEuclid(int a,int b){
	if(a<b){
		gcdExtendedEuclid(b,a);
	}
	
	// base case for 2nd equation i.e. b*x1 + (a/b)*y1 = gcd(b,a%b)
	// via second equation getting result for original equation 
	// i.e original varibles x and y
	// x = y1 and
	// y = x1 - (a/b)*y1
	
	if(b == 0 ){
		Triplet result;
		result.gcd = a;
		result.x = 1;
		result.y = 0;
		return result;
	}
	
	Triplet smallAns = gcdExtendedEuclid(b,a%b);
	
	// for original equation a*x + b*y = gcd(a,b)
	
	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = (smallAns.x - ((a/b)*(smallAns.y)));
	
	return myAns;
}

int main() {
	int a,b;
	cin >> a >> b;
	Triplet ans = gcdExtendedEuclid(a,b);
	cout << "GCD : "<< ans.gcd << endl;
	cout << "  x : "<< ans.x<< endl;
	cout << "  y : "<< ans.y<< endl;
	return 0;
}
