class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        OPT = [float('inf')] * (amount + 1)
        OPT[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    OPT[i] = min(OPT[i], 1 + OPT[i - coin])

        if OPT[amount] == float('inf'):
            return -1
            
        return OPT[amount]