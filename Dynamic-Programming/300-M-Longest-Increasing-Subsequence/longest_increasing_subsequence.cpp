class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        vector<int> OPT(m, 1);
        int result = 1;

        for (int i=m-1; i>=0; i--) {
            for (int j=i+1; j<m; j++) {
                if (nums[i] < nums[j]) {
                    OPT[i] = max(OPT[i], 1 + OPT[j]);
                    if (OPT[i] > result) {
                        result = OPT[i];
                    }
                }
            }
        }
        return result;
    }
};