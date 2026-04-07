class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;

        int state1 = -prices[0];
        int state2 = INT_MIN;
        int state3 = INT_MIN;
        int state4 = INT_MIN;

        for (int i=0; i<n; i++) {
            state1 = max(state1, -prices[i]);
            state2 = max(state2, state1+prices[i]);
            state3 = max(state3, state2-prices[i]);
            state4 = max(state4, state3+prices[i]);
        }
        return max(state4, 0);
    }
};