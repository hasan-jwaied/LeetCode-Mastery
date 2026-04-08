class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        n = len(prices)
        if n <= 1:
            return 0
        
        OPT = [[0]*n for _ in range(k+1)]
        for i in range(1, k+1):
            maxDifference = -prices[0]
            for j in range(1, n):
                OPT[i][j] = max(OPT[i][j-1], maxDifference+prices[j])
                maxDifference = max(maxDifference, OPT[i-1][j] - prices[j])
        return OPT[k][n-1]