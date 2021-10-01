""" 
# JUMP GAME

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
"""

def canJump(nums):
    """check = ["0"] * (len(nums) - 1)
    check.append("G")
    return self.jump(nums, 0, check)"""

    # ONE-PASS SOLUTION
    last = len(nums) - 1
    for i in range(len(nums) - 1, -1, -1):
        if i + nums[i] >= last:
            last = i
            
    return last == 0


"""def jump(self, arr, pos, check):
    if check[pos] != "0":
        return check[pos] == "G"
    
    for i in range(arr[pos], 0, -1):
        if pos + i >= len(arr) or check[pos + i] == "B":
            continue
        if self.jump(arr, pos + i, check):
            check[pos + i] = "G"
            return True
        
    check[pos] = "B"
    return False
"""