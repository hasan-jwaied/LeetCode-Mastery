class Solution:
    def minimumDistance(self, word: str) -> int:
        # define a functions to calculate the dist between two chars
        def dist(c1, c2):
            if c1 is None:
                return 0
            v1, v2 = ord(c1) - 65, ord(c2) - 65
            x1, y1 = v1 // 6, v1 % 6
            x2, y2 = v2 // 6, v2 % 6
            return abs(x1 - x2) + abs(y1 - y2)

        # init a memo
        memo = {}
        
        # define a dynamic programming function to track both fingers
        def dp(i, other):
            if i == len(word):
                return 0
            
            if (i, other) in memo:
                return memo[(i, other)]
            
            prev = word[i-1] if i > 0 else None
            curr = word[i]
            
            cost1 = dist(prev, curr) + dp(i + 1, other)
            cost2 = dist(other, curr) + dp(i + 1, prev)
            
            memo[(i, other)] = min(cost1, cost2)
            return memo[(i, other)]
        
        return dp(0, None)