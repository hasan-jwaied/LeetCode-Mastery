class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        
        vector<vector<int>> OPT(k+1, vector<int>(n, 0));
        for (int i=1; i<=k; i++) {
                int maxDiff = -prices[0];
            for (int j=1; j<n; j++) {
                OPT[i][j] = max(OPT[i][j-1], prices[j]+maxDiff);
                maxDiff = max(maxDiff, OPT[i-1][j]-prices[j]);
            }
        }
        return OPT[k][n-1];
    }
};