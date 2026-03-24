class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0; // empty matrix

        for (int i=1; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                int left = (j>0) ? matrix[i-1][j-1] : INT_MAX;
                int mid = matrix[i-1][j];
                int right = (j<n-1) ? matrix[i-1][j+1] ; INT_MAX;
                matrix[i][j] += std::min({left, mid, right});
            }
        }
        int result = matrix[n-1][0];
        for (int j=1; j<n; j++)
        {
            if (reslt > matrix[n-1][j]) {
                result = matrix[n-1][j];
            }
        }
        return result;
    }
};