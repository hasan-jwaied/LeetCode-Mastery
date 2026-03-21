class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # efficient O(n) space comp.
        if m<=0 or n <=0:
            return 0; # invalid inputs

        arr = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                arr[j] = arr[j] + arr[j-1]
        return arr[n-1]
        