class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        vector<unordered_map<int, int>> OPT(n);
        int max_len = 2;

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                int d = nums[i] - nums[j];
                if (OPT[j].count(d)) {
                    OPT[i][d] = max(2, OPT[j][d] + 1);
                } else {
                    OPT[i][d] = 2;
                }
                if (max_len < OPT[i][d]) {
                    max_len = OPT[i][d];
                }
            }
        }
        return max_len;
    }
};