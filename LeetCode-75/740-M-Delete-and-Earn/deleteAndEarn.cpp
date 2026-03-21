class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int len = nums.size();
        int maximum = *std::max_element(nums.begin(), nums.end());
        if (maximum == 0) return 0;

        std::vector<int> hash(maximum+1, 0);
        for (int i=0; i<len; i++)
        {
            hash[nums[i]] += nums[i];
        }

        int prev2 = hash[0];
        int prev1 = hash[0]>hash[1]?hash[0]:hash[1];
        int curr = 0;
        for (int j=2; j<=maximum; j++)
        {
            curr = prev2+hash[j]>prev1? prev2+hash[j]: prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;

    }
};