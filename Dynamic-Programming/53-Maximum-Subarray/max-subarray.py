class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        best, current_sum = nums[0], nums[0]        
        for num in nums[1:]:
            current_sum = max(num, current_sum + num)
            best = max(best, current_sum)
        return best