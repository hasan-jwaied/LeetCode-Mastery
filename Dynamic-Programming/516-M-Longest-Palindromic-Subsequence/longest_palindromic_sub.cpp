class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n <= 1) return n;

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        vector<vector<int>> OPT(n+1, vector<int>(n+1, 0));

        for (int i=1; i<n+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (s[i-1] == rev_s[j-1])
                    OPT[i][j] = 1 + OPT[i-1][j-1];
                else
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);
            }
        }
        return OPT[n][n];
    }
};