class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++)
            {
                int left = (j>0) ? matrix[i-1][j-1]:Integer.MAX_VALUE;
                int mid = matrix[i-1][j];
                int right = (j<n-1) ? matrix[i-1][j+1]:Integer.MAX_VALUE;
                
                int temp_min = Math.min(left, right);
                matrix[i][j] += Math.min(mid, temp_min);
            }
        }

        int result = matrix[n-1][0];
        for(int j=1; j<n; j++)
        {
            if (result > matrix[n-1][j])
                    result = matrix[n-1][j];
        }

        return result;
    }
}