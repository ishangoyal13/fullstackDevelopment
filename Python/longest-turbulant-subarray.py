#Longest Turbulant Subarray
'''
Given an integer array `arr`, return the length of a maximum size turbulent subarray of `arr`.

A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray `[arr[i], arr[i + 1], ..., arr[j]]` of `arr` is said to be turbulent if and only if:

- For `i <= k < j`:

        * `arr[k] > arr[k + 1]` when `k` is odd, and
        * `arr[k] < arr[k + 1]` when `k` is even.

- Or, `for i <= k < j`:

        * `arr[k] > arr[k + 1]` when `k` is even, and
        * `arr[k] < arr[k + 1]` when `k` is odd.
'''

class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        if len(arr) < 2:
            return len(arr)
        res = 1
        cur = 1
        for i in range(0, len(arr)-1):
            if cur>1:
                if  (gt and arr[i] > arr[i+1]) or ((not gt) and arr[i] < arr[i+1]):
                    cur += 1
                    gt=not gt
                elif arr[i]==arr[i+1]:
                    res=max(res, cur)
                    cur=1
                else:
                    res=max(res, cur)
                    cur=2
                    gt=arr[i]<arr[i+1]
            elif arr[i]!=arr[i-1]:
                cur=2
                gt=arr[i]<arr[i+1]
        return max(res, cur)
