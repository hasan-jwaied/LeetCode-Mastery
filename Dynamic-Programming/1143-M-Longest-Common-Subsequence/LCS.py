class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        t1 = len(text1)
        t2 = len(text2)
        
        if t1 == 0 or t2 == 0:
            return 0

        mat = [[0] * (t2 + 1) for _ in range(t1 + 1)]

        for i in range(1, t1 + 1):
            for j in range(1, t2 + 1):
                if text1[i-1] == text2[j-1]:
                    mat[i][j] = 1 + mat[i-1][j-1]
                else:
                    mat[i][j] = max(mat[i-1][j], mat[i][j-1])
                    
        return mat[t1][t2]