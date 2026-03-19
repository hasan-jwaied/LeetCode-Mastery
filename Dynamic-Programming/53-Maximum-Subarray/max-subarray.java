class Solution {
    public int maxSubArray(int[] nums) {
        int len = nums.length;
        int best=nums[0], sum=nums[0];
        for (int i=1; i<len; i++)
        {
            sum = Math.max(nums[i], sum+nums[i]);
            best = Math.max(best, sum);
        }
        return best;
    }
}