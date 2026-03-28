class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        if n <= 1:
            return n
        rev_s = s[::-1]

        OPT = [[0]*(n+1) for _ in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, n+1):
                if s[i-1] == rev_s[j-1]:
                    OPT[i][j] = 1 + OPT[i-1][j-1]
                else:
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1])
        return OPT[n][n]