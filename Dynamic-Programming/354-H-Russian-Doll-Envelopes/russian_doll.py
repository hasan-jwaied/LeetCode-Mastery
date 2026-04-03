class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        DP = []

        for w, h in envelopes:
            i = bisect_left(DP, h)
            if i==len(DP):
                DP.append(h)
            else:
                DP[i] = h
        return len(DP)