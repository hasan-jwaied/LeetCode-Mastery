class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        m = amount
        n = len(coins)
        OPT = [[0] * (n+1) for _ in range(m+1)]

        for j in range(n+1):
            OPT[0][j] = 1
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                cj = coins[j-1]
                if cj > i:
                    OPT[i][j] = OPT[i][j-1]
                else:
                    OPT[i][j] = OPT[i][j-1] + OPT[i-cj][j]
        return OPT[m][n]