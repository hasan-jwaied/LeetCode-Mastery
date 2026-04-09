class Solution:
    def factorial(self, n: int) -> int:
        if n <= 1:
            return 1
        return self.factorial(n-1)*n

    def numTrees(self, n: int) -> int:
        if n <= 1:
            return 1
        return self.factorial(2*n)//(self.factorial(n)*self.factorial(n+1))