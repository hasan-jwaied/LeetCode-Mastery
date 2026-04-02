class Solution:
    def longestArithSeqLength(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 1:
            return n
        
        OPT: list[dict[int, int]] = [{} for _ in range(n)]
        max_len = 2

        for i in range(n):
            for j in range(i):
                d = nums[i] - nums[j]
                if d in OPT[j]:
                    OPT[i][d] = max(2, OPT[j][d] + 1)
                else:
                    OPT[i][d] = 2
                
                if max_len < OPT[i][d]:
                    max_len = OPT[i][d]
        return max_len