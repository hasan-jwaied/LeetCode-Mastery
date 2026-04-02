import collections
class Solution:
    def longestSubsequence(self, arr: list[int], difference: int) -> int:
        if not arr:
            return 0
            
        seen = collections.Counter()
        for num in arr:
            seen[num] = seen[num - difference] + 1
        return max(seen.values())