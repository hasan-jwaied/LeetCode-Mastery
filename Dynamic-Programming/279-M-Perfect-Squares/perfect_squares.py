class Solution:
    def numSquares(self, n: int) -> int:
        OPT = [n] * (n+1)
        OPT[0] = 0

        for target in range(1, n+1):
            for s in range(1, target+1):
                square = s*s
                if target - square < 0:
                    break
                OPT[target] = min(OPT[target], OPT[target-square] + 1)
        return OPT[n]