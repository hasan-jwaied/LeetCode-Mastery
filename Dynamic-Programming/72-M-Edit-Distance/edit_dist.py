class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word2)
        n = len(word1)
        if m==0:
            return n
        if n==0:
            return m
        
        mat = [[0]*(n+1) for _ in range(m+1)]
        
        for i in range(1, n+1):
            mat[0][i] = i
        for j in range(1, m+1):
            mat[j][0] = j
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word2[i-1] == word1[j-1]:
                    mat[i][j] = mat[i-1][j-1]
                else:
                    mat[i][j] = 1 + min(mat[i][j-1], mat[i-1][j-1], mat[i-1][j])
        return mat[m][n]