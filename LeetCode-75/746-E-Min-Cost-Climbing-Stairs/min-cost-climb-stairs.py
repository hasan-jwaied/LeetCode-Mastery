class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        prev1, prev2, length = 0, 0, len(cost)
        for i in range(2, length + 1):
            prev2, prev1 = prev1, min(cost[i-1] + prev1, cost[i-2] + prev2)
        return prev1