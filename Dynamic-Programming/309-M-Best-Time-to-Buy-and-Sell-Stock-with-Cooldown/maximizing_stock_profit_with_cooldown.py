class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        if n <= 1 :
            return 0
        
        hold = -prices[0]
        sold = 0
        rest = 0

        for i in range(1, n):
            next_hold = max(hold, rest - prices[i])
            next_sold = hold + prices[i]
            next_rest = max(rest, sold)

            hold = next_hold
            sold = next_sold
            rest = next_rest
        return max(sold, rest)