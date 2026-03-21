class Solution:
    def tribonacci(self, n: int) -> int:
        if n<=1:
            return n
        elif n==2:
            return 1
        else:
            prev3=0
            prev2=1
            prev1=1
            curr=0
            for i in range(3, n+1):
                curr=prev3+prev2+prev1
                prev3=prev2
                prev2=prev1
                prev1=curr
            return curr
        