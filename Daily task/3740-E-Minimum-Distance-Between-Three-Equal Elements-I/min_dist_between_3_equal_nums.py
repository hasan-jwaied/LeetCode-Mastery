class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        n = len(nums)
        if n < 3:
            return -1

        indices:list[list[int]] = [[] for _ in range(n+1)]
        
        for i in range(n):
            indices[nums[i]].append(i)
        
        result = float('inf')
        
        for num in range(n+1):
            count = len(indices[num])
            if count >= 3:
                for m in range(count-2):
                    i = indices[num][m]
                    k = indices[num][m+2]
                    dist = 2 * (k-i)
                    
                    if dist < result:
                        result = dist
        
        if result == float('inf'):
            return -1
        return result