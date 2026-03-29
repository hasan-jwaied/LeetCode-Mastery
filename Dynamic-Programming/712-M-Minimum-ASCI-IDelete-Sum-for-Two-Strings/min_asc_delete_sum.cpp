class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> OPT(m+1, vector<int>(n+1, 0));
        for (int i=1; i<n+1; i++)
            OPT[0][i] = OPT[0][i-1] + s2[i-1];

        for (int j=1; j<m+1; j++)
            OPT[j][0] = OPT[j-1][0] + s1[j-1];
        
        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (s1[i-1] == s2[j-1])
                    OPT[i][j] = OPT[i-1][j-1];
                else
                    OPT[i][j] = min(s1[i-1]+OPT[i-1][j], s2[j-1]+OPT[i][j-1]);
            }
        }

        return OPT[m][n];
    }
};