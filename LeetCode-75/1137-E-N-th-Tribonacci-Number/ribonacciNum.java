class Solution {
    public int tribonacci(int n) {
        if (n<=1) return n;
        else if (n==2) return 1;
        else {
            int prev3=0;
            int prev2=1;
            int prev1=1;
            int curr = 0;

            for (int k=3; k<=n; k++)
            {
                curr = prev1+prev2+prev3;
                prev3=prev2;
                prev2=prev1;
                prev1=curr;
            }
            return curr;
        }       
    }
}