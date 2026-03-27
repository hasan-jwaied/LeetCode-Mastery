class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        n = len(s)
        if n==0:
            return True
        my_set = set(wordDict)
        OPT = [False] * (n+1)
        OPT[0] = True
        
        for i in range(1, n+1):
            for j in range(i):
                if OPT[j] == True and s[i:j] in my_set:
                    OPT[i] = True
                    break
        return OPT[n]