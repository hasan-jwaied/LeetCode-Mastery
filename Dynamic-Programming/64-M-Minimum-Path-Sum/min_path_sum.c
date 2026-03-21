int minimum (int a, int b)
{
    return a<b?a:b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if (!grid || !gridColSize || gridSize<=0) return 0; // invalid inputs
    // gridSize = m-diminsion
    // for each column, we have the size in girdColSize,
    //let's build the accumulation matrix
    int m = gridSize;
    int n = gridColSize[0];

    int** mat = malloc(sizeof(int *)*m);
    if (!mat) return -909; // failed to allocate memory;

    for (int i=0; i<m; i++)
    {
        mat[i] = calloc(sizeof(int), n);
        if (!mat[i])
        {
            for (int k=0; k<i; k++)
            {
                free(mat[k]);
            }
            free(mat);
            return -909;
        }
    }

    mat[0][0] = grid[0][0];
    for (int j=1; j<n; j++)
    {
        mat[0][j] = grid[0][j] + mat[0][j-1];
    }

    for (int i=1; i<m; i++)
    {
        mat[i][0] = grid[i][0] + mat[i-1][0];
    }

    for (int i=1; i<m; i++)
    {
        for (int j=1; j<n; j++)
        {
            mat[i][j] = grid[i][j] + minimum(mat[i-1][j], mat[i][j-1]);
        }
    }
    int result = mat[m-1][n-1];

    for (int i=0; i<m; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return result;
}