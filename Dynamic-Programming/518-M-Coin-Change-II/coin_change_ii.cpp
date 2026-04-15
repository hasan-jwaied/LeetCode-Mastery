class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = amount;
        int n = coins.size();

        vector<vector<int>> OPT (m+1, vector<int>(n+1, 0));
        for (int j=0; j<n+1; j++) {
            OPT[0][j] = 1;
        }

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                int cj = coins[j-1];
                if (cj > i) {
                    OPT[i][j] = OPT[i][j-1];
                } else {
                    OPT[i][j] = OPT[i][j-1] + OPT[i-cj][j];
                }
            }
        }
        return OPT[m][n];
    }
};