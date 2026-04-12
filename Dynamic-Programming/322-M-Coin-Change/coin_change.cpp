class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> OPT(amount + 1, amount+1);
        OPT[0] = 0;
        
        for (int i=1; i<amount+1; i++) {
            for (const auto& coin : coins) {
                if (coin <= i)
                    OPT[i] = min(OPT[i], OPT[i-coin] + 1);
            }
        }
        if (OPT[amount] == amount+1) {
            return -1;
        }
        return OPT[amount];
    }
};