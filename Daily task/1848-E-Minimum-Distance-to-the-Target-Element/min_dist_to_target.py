class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        n = len(nums)

        result = float('inf')

        for i in range(n):
            if nums[i] == target:
                if result > abs(i-start):
                    result = abs(i - start)
        return result