class Solution:
    def rob(self, nums: list[int]) -> int:
        length = len(nums)
        if length == 0:
            return -99 # empty list
        if length == 1:
            return nums[0]
        
        prev2 = nums[0]
        prev1 = max(nums[0], nums[1])
        curr = 0
        
        for i in range(2, length):
            curr = max(nums[i]+prev2, prev1)
            prev2 = prev1
            prev1 = curr
        return prev1