class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if (len == 0) return -99; // empty array
        if (len == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
        int curr = 0;
        for (int k=2; k<len; k++)
        {
            curr = Math.max(prev2+nums[k], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}