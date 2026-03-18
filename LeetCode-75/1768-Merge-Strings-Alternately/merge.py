class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        w1_len = len(word1)
        w2_len = len(word2)
        result = ""

        i, j=0, 0
        while (i<w1_len and j<w2_len):
            result += word1[i]
            result += word2[j]
            i += 1
            j += 1
        
        if i<w1_len:
            result += word1[i::]

        if j<w2_len:
            result += word2[j::]

        return result        