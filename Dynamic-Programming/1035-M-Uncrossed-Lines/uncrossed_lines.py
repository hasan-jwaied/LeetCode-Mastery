class Solution:
    def maxUncrossedLines(self, nums1: list[int], nums2: list[int]) -> int:
        n = len(nums1)
        m = len(nums2)

        OPT = [[0]*(n+1) for _ in range(m+1)]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if nums2[i-1] == nums1[j-1]:
                    OPT[i][j] = 1 + OPT[i-1][j-1]
                else:
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1])
        return OPT[m][n]