# Length of the Longest increasing substring

import bisect
def lengthOfLIS(nums) -> int:
    sub = []
    for num in nums:
        
        i = bisect.bisect_left(sub, num)
        if i == len(sub):
            sub.append(num)
        else:
            sub[i] = num
    return len(sub)
nums=[10,9,2,5,3,7,101,18]
print(lengthOfLIS(nums))


#function to find out where This function returns the position in the sorted list, 
# where the number passed in argument can be placed so as to maintain the resultant list in sorted order
