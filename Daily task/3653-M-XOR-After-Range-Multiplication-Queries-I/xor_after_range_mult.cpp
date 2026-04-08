class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7; 
        int n = queries.size();
        int m = nums.size();

        for (int i = 0; i < n; i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];

            for (int j = li; j <= ri; j += ki) {
                nums[j] = (1LL * nums[j] * vi) % MOD; 
            }
        }

        int result = 0;
        for (int i = 0; i < m; i++) {
            result ^= nums[i]; 
        }
        return result;
    }
};