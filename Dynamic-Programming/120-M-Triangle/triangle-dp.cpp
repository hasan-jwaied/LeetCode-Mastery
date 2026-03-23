class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        for (int i=sz-2; i>=0; i--)
        {
            for (int j=0; j<triangle[i].size(); j++)
            {
                triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};