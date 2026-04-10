class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();        
        if (n < 3)
            return -1;
        
        vector<vector<int>> indices(n + 1);
        
        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        
        for (int num = 0; num <= n; num++) {            
            int count = indices[num].size();
            if (count >= 3) {
                for (int m = 0; m < count - 2; m++) {
                    int i = indices[num][m];
                    int k = indices[num][m + 2];                    
                    int dist = 2 * (k - i);
                    
                    if (dist < min_dist) {
                        min_dist = dist;
                    }
                }
            }
        }
        
        if (min_dist == INT_MAX) {
            return -1;
        }
        
        return min_dist;
    }
};