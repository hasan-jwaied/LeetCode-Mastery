class Solution:
    def minInsertions(self, s: str) -> int:
        # we first check if reversed s equal to s, then it is already palindrome -> return 0
        if s == s[::-1]:
            return 0
        # take the reversed string of s, find LCS, it is palindrome. and the longest palindrome in s
        # after that we can now how many insertions we need, it is len(s) - len(longest_palindrome)

        reversed_s = s[::-1]
        s_len = len(s)
        OPT = [[0] * (s_len + 1) for _ in range(s_len + 1)]
        for i in range(1, s_len+1):
            for j in range(1, s_len+1):
                if s[i-1] == reversed_s[j-1]:
                    OPT[i][j] = OPT[i-1][j-1] + 1
                else:
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1])
        return s_len - OPT[s_len][s_len]