class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<unsigned int>> OPT(m+1, vector<unsigned int>(n+1, 0));
        for (int j=0; j<n+1; j++) {
            OPT[0][j] = 1;
        }

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (i>j) continue;

                if (s[j-1] == t[i-1])
                    OPT[i][j] = OPT[i-1][j-1] + OPT[i][j-1];
                else
                    OPT[i][j] = OPT[i][j-1];
            }
        }
        return OPT[m][n];
    }
};