class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        
        vector<int> factory_flat; 
        for (int i = 0; i < factory.size(); i++) {
            for (int j = 0; j < factory[i][1]; j++) {
                factory_flat.push_back(factory[i][0]);
            }
        }

        int m = factory_flat.size();

        long long INF = 1e15; 
        vector<vector<long long>> OPT(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i < n + 1; i++) {
            OPT[i][0] = INF;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                OPT[i][j] = min(OPT[i][j-1], OPT[i-1][j-1] + abs(robot[i-1] - factory_flat[j-1]));
            }
        }

        return OPT[n][m];
    }
};