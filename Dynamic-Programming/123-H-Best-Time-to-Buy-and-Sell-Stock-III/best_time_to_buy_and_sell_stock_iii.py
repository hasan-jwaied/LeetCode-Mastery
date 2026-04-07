class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        state1, state2, state3, state4 = -prices[0], float('-inf'), float('-inf'), float('-inf') 
        for price in prices:
            state1 = max(state1, -price)
            state2 = max(state2, state1+price)
            state3 = max(state3, state2-price)
            state4 = max(state4, state3+price)
        return max(state4, 0) 