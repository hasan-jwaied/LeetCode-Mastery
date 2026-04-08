class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7

        for li, ri, ki, vi in queries:            
            for j in range(li, ri + 1, ki):
                nums[j] = (nums[j] * vi) % MOD
                
        result = 0
        for num in nums:
            result ^= num
            
        return result