class Solution:
    def findNumberOfLIS(self, nums: list[int]) -> int:
        n = len(nums)
        if n <=1 :
            return n
        
        OPT = [1] * n
        COUNT = [1] * n

        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                if nums[i] < nums[j]:
                    if OPT[i] < 1 + OPT[j]:
                        OPT[i] = 1 + OPT[j]
                        COUNT[i] = COUNT[j]
                    elif OPT[i] == 1 + OPT[j]:
                        COUNT[i] += COUNT[j]
        global_max = max(OPT)
        result = 0
        for i in range(n):
            if OPT[i] == global_max:
                result += COUNT[i]
        return result