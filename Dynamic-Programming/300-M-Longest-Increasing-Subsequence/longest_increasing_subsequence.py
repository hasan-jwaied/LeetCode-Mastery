class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        m = len(nums)
        OPT = [1] * m

        for i in range(m-1, -1, -1):
            for j in range(i+1, m):
                if nums[i] < nums[j]:
                    OPT[i] = max(OPT[i], 1 + OPT[j])
        return max(OPT)