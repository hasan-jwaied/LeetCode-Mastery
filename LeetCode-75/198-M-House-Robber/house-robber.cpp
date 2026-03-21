class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return -99; // invalid input.
        int len = nums.size();
        if (len==1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        int curr = 0;
        for (int k=2; k<len; k++)
        {
            curr = max(nums[k]+prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};