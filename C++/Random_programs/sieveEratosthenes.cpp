#include <iostream>
using namespace std;

// algo
// make seive first i.e initialize a bool array of size n+1 and assign all to be true
// make a[0] and a[1] false as 0 and 1 are not prime

// then iterate from 2 to sqrt(n) and for every multiple of that number starting from i*i till n make it false
// then at last count how many true are there in array they are prime numbers



// complexity - O(Nlog(logN))

int main() {
	int n, cnt = 0 ;
	cin >> n;
	bool * a = new bool[n+1];
	for(int i = 0; i <= n; i++) a[i] = true;	
	a[0] = false;
	a[1] = false;
	
	// --> optimizations <--
	// 1. from 2 to root(n)
	// 2. make all multiples false from i*i till n
	
	for(int i = 2; i*i<=n;i++){
		if(a[i] == true){
			for(int j = i*i;j<=n;j += i ){
				a[j] = false;
			}			
		}

	}
	//for(int i =0;i<=n;i++){
		//cout << i << " : " << a[i] << endl;
	//}
	for(int i =0;i<=n;i++){
		if(a[i] == true) cnt ++;
	}
	cout << endl;
	cout << cnt << endl;
    
    delete [] a;
    
	return 0;
}
