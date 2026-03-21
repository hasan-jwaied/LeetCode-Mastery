class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return nums[0]
        
        maximum = max(nums)
        hash = [0]*(maximum+1)
        for i in range(length):
            hash[nums[i]] += nums[i]
            
        prev2 = hash[0]
        prev1 = max(hash[0], hash[1])
        curr = 0
        for j in range(2, maximum+1):
            curr = max(prev2 + hash[j], prev1)
            prev2=prev1
            prev1=curr
        return prev1