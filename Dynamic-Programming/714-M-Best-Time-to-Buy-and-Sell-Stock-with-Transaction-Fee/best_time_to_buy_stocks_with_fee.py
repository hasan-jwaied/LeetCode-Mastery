class Solution:
    def maxProfit(self, prices: list[int], fee: int) -> int:
        n = len(prices)
        if n <= 1:
            return 0
        
        hold = -prices[0] # we bought in day 0
        free = 0 # we did nothing in day 0
        
        for i in range(1, n):
            next_hold = max(hold, free - prices[i])
            next_free = max(free, hold + prices[i] - fee)
            
            hold = next_hold
            free = next_free
        
        return free        