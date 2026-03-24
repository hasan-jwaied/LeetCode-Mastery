int minimum_3(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    return min_val;
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    if (n==0) return 0;
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            int left = (j>0) ? matrix[i-1][j-1] : INT_MAX;
            int mid = matrix[i-1][j];
            int right = (j < n-1) ? matrix[i-1][j+1] : INT_MAX;

            matrix[i][j] += minimum_3(left, mid, right);
        }
    }
    int result = matrix[n-1][0];
    for (int j=1; j<n; j++)
    {
        if (result > matrix[n-1][j])
            result = matrix[n-1][j];
    }

    return result;
}