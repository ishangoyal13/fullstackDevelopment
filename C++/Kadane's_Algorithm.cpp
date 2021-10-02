//  KADANE'S ALGORITHM

// Why Kadane’s Algorithm ?
// It is used to find out the maximum subarray sum from an array of integers. 

// Two methods to find the maximum subarray sum is
//     1. The brute force method
//     2. Kadane’s algorithm

// Kadane’s algorithm is an iterative dynamic programming algorithm. It uses optimal sub-structures. By this, we mean that to calculate the maximum subarray ending at a particular position, we use a related, smaller subproblem (the maximum subarray ending at the previous position). Because of this, it is dynamic programming. Kadane’s algorithm uses a greedy and dynamic approach.


// -> BRUTE FORCE CODE (C++):

    #include <bits/stdc++.h>
    using namespace std;

    void maxSumSubarray(int arr[], int n){
        vector<int> ans;

        //choosing the starting point of subarray
        for(int i=0; i<n; i++){

            //choosing the end point of subarray
            for(int j=i; j<n; j++){

                int temp = 0;
                //finding the sum of the subarray

                for(int k=i; k<=j; k++)
                    temp = temp + arr[k];

                // storing sum in an ans vector
                ans.push_back(temp);
            }
        }
        
        cout <<"Maximum sum of contiguous subarray is: "<< *max_element(ans.begin(), ans.end())<<"\n";
        //To print the maximum sum contiguous subarray
    }

    int main(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int arr[n];
            for(int i=0; i<n; i++){
                cin>>arr[i];
            }
            maxSumSubarray(arr, n);
        }
        return 0;
    }


// -> KADANE ALGORITHM CODE (C++):

    #include<iostream>
    using namespace std;

    int kadaneAlgorithm(int arr[], int n){
        //stores the maximum sum subarray sum found so far
        
        int max_so_far = 0;
        
        //stores the maximum sum of subarray at the current position

        int max_ending_here = 0;

        for (int i = 0; i < n; i++){
            // adding the current element to maximum sum ending at previous index i-1

            max_ending_here = max_ending_here + arr[i];

            // this helps in avoiding getting any negative sum

            if(max_ending_here < 0)
                max_ending_here = 0;
            
            // getting the maximum sum in result by finding out the maximum from max_so_far and max_ending_here

            if(max_so_far < max_ending_here)
                max_so_far = max_ending_here;  
        }  
        
        return max_so_far;
    }

    int main() {
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int arr[n];
            for(int i=0; i < n; i++){
                cin>>arr[i];
            }
            cout <<"Maximum sum of contiguous subarray is: "<<kadaneAlgorithm(arr, n)<<"\n";
        }
        return 0;
    }

// The time complexity of Kadane’s algorithm is O(n).
// The space complexity of Kadane’s algorithm is O(1).



