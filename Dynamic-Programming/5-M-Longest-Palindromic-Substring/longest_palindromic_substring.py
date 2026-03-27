class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 1:
            return s
            
        mat = [[0] * n for _ in range(n)]
        max_len = 1
        start_idx = 0
        
        for i in range(n):
            mat[i][i] = 1
            
        for i in range(n - 1):
            if s[i] == s[i+1]:
                mat[i][i+1] = 1
                start_idx = i
                max_len = 2
                
        for L in range(3, n + 1):
            for i in range(n - L + 1):
                j = i + L - 1                
                if s[i] == s[j] and mat[i+1][j-1] == 1:
                    mat[i][j] = 1
                    
                    if max_len < L:
                        max_len = L
                        start_idx = i
                        
        return s[start_idx : start_idx + max_len]