class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());

        vector<vector<int>> OPT(len+1, vector<int>(len+1, 0));
        for (int i=1; i<len+1; i++) {
            for (int j=1; j<len+1; j++) {
                if (s[i-1] == reversed_s[j-1]) {
                    OPT[i][j] = 1 + OPT[i-1][j-1];
                } else {
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);
                }
            }
        }
        return len - OPT[len][len];
    }
};