class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double ans = 0;
        vector<int> v;
        for(int i=0;i<m;i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            v.push_back(nums2[i]);
        }
        
        int len = v.size();
        sort(v.begin(),v.end());
        if(len%2 != 0){
            ans = v[(len/2)];
        }
        else{
            ans = v[len/2] + v[(len/2)-1];
            ans = ans/2;
        }
        return ans;
        
    }
};