#include<bits/stdc++.h>
using namespace std;
 int sortColors(int nums[],int n) {
        int i=0, l = 0, r = n-1;
        if(n < 2)
            cout<<nums[i];

        while(l<r&&i<n){
            if(nums[i]==0){
                swap(nums[i++],nums[l++]);
            }
            else if(nums[i]==2){
                swap(nums[i],nums[r--]);
                n--;
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<nums[i];
        }
    }
 /*void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;

        for(auto i : nums)
        {
            if(i == 0)
            {
                ++red;
            }
            else if(i == 1)
            {
                ++white;
            }

        }

        for(int i=0; i < nums.size(); ++i)
        {
            if(red)
            {
                nums[i] = 0;
                --red;
            }
            else if(white)
            {
                nums[i] = 1;
                --white;
            }
            else
                nums[i] = 2;
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
    }*/
int main(){
    int n;
        cin>>n;
            int nums[n];
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
    cout<<sortColors(nums,n);
}
