class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        if (cost.empty()) return -98;
        int len = cost.size();
        std::vector<int> temp(len+1, 0);
        for (int k=2; k<=len; k++)
        {
            temp[k] = std::min(temp[k-1]+cost[k-1], temp[k-2]+cost[k-2]);
        }
        
        int result = temp[len];
        return result;
    }
};

// OPTIMIZED (O(1) SPACE COMPLEX. SOLUTION):
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        if (cost.empty()) return -99; // empty input.
        int len = cost.size();

        int prev1 = 0;
        int prev2 = 0;
        int curr = 0;
        for (int k=2; k<=len; k++)
        {
            curr = std::min(cost[k-1] + prev1, cost[k-2] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};