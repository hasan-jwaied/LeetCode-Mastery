class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        int n = nums1.size();

        vector<vector<int>> OPT(m+1, vector<int>(n+1, 0));

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (nums1[j-1] == nums2[i-1]) {
                    OPT[i][j] = 1 + OPT[i-1][j-1];
                } else {
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);
                }
            }
        }
        return OPT[m][n];
    }
};