//Implementation of Jump Search
//Time Complexity : O(√n) 
//Auxiliary Space : O(1)

#include<bits/stdc++.h>
using namespace std;

int jump_search(int arr[], int n, int k) 
{ 
    int jump = sqrt(n); 
    int index = 0; 
    while (arr[jump] <= k && jump < n) { 
        index = jump; 
        jump += sqrt(n); 
        if (jump > n-1) 
            return -1; 
    } 

    for(int j=index;j<jump;j++){ 
        if (arr[j]==k) 
            return j; 
    }  
    return -1; 
} 

int main(){
int n,key;
  cout << "Enter size of the array:"<<endl;
  cin >> n;
  cout << "Enter the array elements:"<<endl;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter the key to be searched:"<<endl;
  cin >> key;
  int res = jump_search(arr,n,key);
  if (res != -1)
    cout << key << " found at index " << res << endl;
  else
    cout << key << " not found in the array" << endl;
  return 0;
}


//This code is contributed by Nikhil-1503
