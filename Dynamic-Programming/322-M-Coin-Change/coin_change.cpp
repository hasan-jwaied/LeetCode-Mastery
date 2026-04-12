class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> OPT(amount + 1, INT_MAX);
        OPT[0] = 0;
        
        for (int i=1; i<amount+1; i++) {
            for (int j=0; i<n; i++) {
                if (coins[j] <= i) {
                    OPT[i] = min(OPT[i], OPT[i-coins[j]]);
                }
            }
        }
        if (OPT[amount] == INT_MAX) {
            return -1;
        }
        return OPT[amount];
    }
};