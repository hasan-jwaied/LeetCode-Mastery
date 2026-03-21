class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int prev1=0;
        int prev2=0;
        int curr = 0;
        int len = cost.length;
        for (int k=2; k<=len; k++)
        {
            curr = Math.min(cost[k-1]+prev1, cost[k-2]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
}