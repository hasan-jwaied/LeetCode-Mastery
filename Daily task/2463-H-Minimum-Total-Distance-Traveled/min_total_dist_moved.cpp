#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort both arrays
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        
        // 1. Fix: Create empty vector without initializing with zeros
        vector<int> factory_flat; 
        for (int i = 0; i < factory.size(); i++) {
            for (int j = 0; j < factory[i][1]; j++) {
                factory_flat.push_back(factory[i][0]);
            }
        }

        // 2. Fix: Update 'm' to be the size of the NEW flattened array
        int m = factory_flat.size();

        // 3. Fix: Use a safely large number for infinity 
        // 1e15 is large enough to act as infinity, but small enough to prevent long long overflow
        long long INF = 1e15; 
        vector<vector<long long>> OPT(n + 1, vector<long long>(m + 1, 0));

        // Base cases
        for (int i = 1; i < n + 1; i++) {
            OPT[i][0] = INF;
        }

        // Fill the DP table
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                OPT[i][j] = min(OPT[i][j-1], OPT[i-1][j-1] + abs(robot[i-1] - factory_flat[j-1]));
            }
        }

        return OPT[n][m];
    }
};