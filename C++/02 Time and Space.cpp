#include <iostream>
#include<cstring>
#include<climits>
using namespace std;

void lps(char array[]) {
	int len = strlen(array);
	bool array_lps[len][len];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			array_lps[i][j] = false;
		}
	}

	for (int diag = 0; diag < len; diag++) {
		int si = 0;
		int ei = diag;
		while (ei < len) {
			if (si == ei) {
				array_lps[si][ei] = true;
			} else if (ei == si + 1) {
				if (array[ei] == array[si]) {
					array_lps[si][ei] = true;
				} else {
					array_lps[si][ei] = false;
				}
			} else {
				if (array[ei] == array[si]) {
					array_lps[si][ei] = array_lps[si+1][ei-1];
				} else {
					array_lps[si][ei] = false;
				}
			}

			si++;
			ei++;
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << array_lps[i][j] << " ";
		}
		cout << endl;
	}
}

void min_swaps(int arr[], int size, int k){
	int count=0;
	for(int i=0; i<size; i++){
		if(arr[i]<k){
			count++;
		}
	}


	int si=0;
	int ei=count-1;
	int udc=0;
	for(int i=si; i<=ei; i++){
		if(arr[i]>=k){
			udc++;
		}
	}

	int omin=INT_MAX;
	while(ei+1 < size){
		if(arr[si]>=k){
			udc=udc-1;
		}
		if(arr[ei+1]>=k){
			udc=udc+1;
		}

		si++;
		ei++;

		if(udc<omin){
			omin=udc;
		}

	}
	cout<<omin<<endl;
}

void loops() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << j << endl;
		}
	}
	int m = 100;
	n = 1000;
	sum = 0;
	for (int i = 0; i < n; i += m) {
		for (int j = 0; j < m; j++) {
			sum = sum + j;
		}
	}

	sum = 0;
	for (int i = n; i >= 1; i = i / 2) {
		sum = sum + i;
	}

	sum = 0;
	int j = 0;
	for (int i = 0; i < n;) {
		j++;
		if (j == n) {
			j = 0;
			i++;
		}
	}

}

int main() {
	/*char array[] = "abccba";
	lps(array);*/
	int arr[]={2,4,5,6,1,2,7,-1,8};
	int k=3;
	min_swaps(arr, 9, k);
	return 0;
}
