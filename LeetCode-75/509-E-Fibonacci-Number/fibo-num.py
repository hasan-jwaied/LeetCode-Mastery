class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        prev2 = 0
        prev1 = 1
        curr = 0
        for i in range(2, n+1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr
        return curr