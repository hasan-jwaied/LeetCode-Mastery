class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;
        else obstacleGrid[0][0] = 1;

        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                obstacleGrid[0][j] = 0;
            } else {
                obstacleGrid[0][j] = obstacleGrid[0][j-1];
            }
        }

        for (int i=1; i<m; i++)
        {
            if (obstacleGrid[i][0] == 0)
                obstacleGrid[i][0] = 1;
            else {
                for (int k=i; k<m; k++)
                    obstacleGrid[k][0] = 0;
                break;
            }
        }

        for (int i=1; i<m; i++)
        {
            for (int j=1; j<n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};