class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;
        
        int prev2 = 0;
        int prev1 = 1;
        int curr = 0;
        for (int k=2; k<=n; k++)
        {
            curr = prev2+prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};