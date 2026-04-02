int longestArithSeqLength(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;

    int min_val = nums[0], max_val = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min_val) min_val = nums[i];
        if (nums[i] > max_val) max_val = nums[i];
    }

    int max_diff = max_val - min_val;
    int offset = max_diff; 
    int diff_range = 2 * max_diff + 1;

    int dp[numsSize][diff_range];
    
    memset(dp, 0, sizeof(dp));

    int max_len = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            int d = nums[i] - nums[j] + offset;

            if (dp[j][d] > 0) {
                dp[i][d] = dp[j][d] + 1;
            } else {
                dp[i][d] = 2; 
            }

            if (dp[i][d] > max_len) {
                max_len = dp[i][d];
            }
        }
    }

    return max_len;
}