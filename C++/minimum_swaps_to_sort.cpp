#include<bits/stdc++.h>
using namespace std;




class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    //BruteForce:O(N^2): Eveyrtime find the el for that index.
	    
	    //Optimal:O(n)
	    int n= nums.size();
	    vector<int> sorted=nums;
	    sort(sorted.begin(), sorted.end());
	    int ans=0;
	    
	    unordered_map<int,int> map;
	    for(int i=0;i<n;i++)
	        map[nums[i]]=i;
	        
	    for(int i=0;i<n;i++)
	    {
	        if(nums[i]==sorted[i])
	            continue;
	        else
	        {
	            ans++;
	            map[nums[i]]=map[sorted[i]];
	            swap(nums[i], nums[map[sorted[i]]]);
	            map[sorted[i]]=i;
	        }
	            
	    }
	   return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}


// IP:
// 9
// 7 16 14 17 6 9 5 3 18
// OP:
// 5