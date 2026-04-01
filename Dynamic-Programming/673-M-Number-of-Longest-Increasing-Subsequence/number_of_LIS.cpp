class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> OPT(n, 1);
        vector<int> count(n, 1);
        
        for (int i=n-2; i>=0; i--) {
            for (int j=i+1; j<n; j++) {
                if (nums[i] < nums[j]) {
                    if (OPT[i] < OPT[j] + 1) {
                        OPT[i] = OPT[j] + 1;
                        count[i] = count[j];
                    }
                    else if (OPT[i] == OPT[j]+1) {
                        count[i] += count[j];
                    }
                }
            }
        }
        int global_max = OPT[0];
        for (int i=1; i<n; i++) {
            if (OPT[i] > global_max)
                global_max = OPT[i];
        }
        int result = 0;
        for (int j=0; j<n; j++) {
            if (OPT[j] == global_max)
                result += count[j];
        }
        return result;
    }
};