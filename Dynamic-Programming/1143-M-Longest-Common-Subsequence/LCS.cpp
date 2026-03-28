class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text2.length();
        int n = text1.length();
        if (m==0 || n == 0) return 0;

        vector<vector<int>> OPT(m+1, vector<int>(n+1, 0));

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (text1[j-1]==text2[i-1]) {
                    OPT[i][j] = 1 + OPT[i-1][j-1];
                } else {
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);
                }
            }
        }
        return OPT[m][n];
    }
};