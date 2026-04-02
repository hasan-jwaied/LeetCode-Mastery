class Solution:
    def findLongestChain(self, pairs: list[list[int]]) -> int:
        n = len(pairs)
        if n <= 1:
            return n
        
        pairs.sort(key=lambda x:x[1])

        OPT = [1] * n

        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                if pairs[i][1] < pairs[j][0]:
                    OPT[i] = max(OPT[i], OPT[j]+1)
        return max(OPT)