'''
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value
Example 1: 
            Input: nums = [5,7,7,8,8,10], target = 8
            Output: [3,4]
Example 2:
            Input: nums = [5,7,7,8,8,10], target = 6
            Output: [-1,-1]
'''


class Solution:
    def searchRange(self, nums, target):
        ans = [-1, -1]
        start = self.search(nums, target, True)
        end = self.search(nums, target, False)
        ans[0] = start
        ans[1] = end
        return ans

    def search(self, nums, target, findFirst=True):
        ans = -1
        start = 0
        end = len(nums)-1
        while(start <= end):
            mid = start+(end-start)//2
            if target < nums[mid]:
                end = mid-1
            elif target > nums[mid]:
                start = mid+1
            else:
                ans = mid
                if(findFirst):
                    end = mid-1
                else:
                    start = mid+1
        return ans
