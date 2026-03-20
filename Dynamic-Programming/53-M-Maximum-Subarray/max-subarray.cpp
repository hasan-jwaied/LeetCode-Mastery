class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // applaying Kadane's Algo.
        int len = nums.size();
        int best=nums[0], sum=nums[0];
        for (int k=1; k<len;k++)
        {
            sum = max(nums[k], sum+nums[k]);
            best = max(best, sum);
        }
        return best;
    }
};