class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        if (n <= 1)
            return 0;

        int hold = -prices[0];
        int free = 0;


        for (int i=1; i<n; i++) {
            int next_hold = max(hold, free - prices[i]);
            int next_free = max(free, hold + prices[i] - fee);

            hold = next_hold;
            free = next_free;
        }
        return free;
    }
};