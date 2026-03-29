class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        
        OPT = [[0]* (n+1) for _ in range(m+1)]
        for i in range(1, n+1):
            OPT[0][i] = ord(s2[i-1]) + OPT[0][i-1]
        
        for j in range(1, m+1):
            OPT[j][0] = ord(s1[j-1]) + OPT[j-1][0]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if s1[i-1] == s2[j-1]:
                    OPT[i][j] = OPT[i-1][j-1]
                else:
                    OPT[i][j] = min(ord(s1[i-1])+OPT[i-1][j],ord(s2[j-1])+OPT[i][j-1])

        return OPT[m][n]