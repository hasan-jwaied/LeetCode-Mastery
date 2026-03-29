class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(t)
        n = len(s)
        OPT = [[0] * (n+1) for _ in range(m+1)]
        OPT[0][0] = 1

        for k in range(1, n+1):
            OPT[0][k] = 1

        for i in range(1, m+1):
            for j in range(1, n+1):
                if i>j:
                    continue
                if t[i-1] == s[j-1]:
                    OPT[i][j] = OPT[i-1][j-1] + OPT[i][j-1]
                else:
                    OPT[i][j] = OPT[i][j-1]
        
        return OPT[m][n]