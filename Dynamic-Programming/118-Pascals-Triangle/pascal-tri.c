int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (!returnSize || !returnColumnSizes || numRows < 0) return NULL;
    
    int** ans = malloc(sizeof(int*) * numRows);
    if (!ans) return NULL;
    
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    if (!(*returnColumnSizes)) {
        free(ans);
        return NULL;
    }
    
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        ans[i] = malloc(sizeof(int) * (i + 1));
        
        if (!ans[i]) {
            for (int w = 0; w < i; w++) free(ans[w]);
            free(ans);
            free(*returnColumnSizes);
            return NULL;
        }

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                ans[i][j] = 1;
            } else {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        (*returnColumnSizes)[i] = i + 1;
    }

    return ans;
}