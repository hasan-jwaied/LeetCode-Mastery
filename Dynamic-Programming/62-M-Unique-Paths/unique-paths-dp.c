int uniquePaths(int m, int n) {
    if (m<=0 || n<=0) return 0; // invalid inputs
    int** mat = calloc(sizeof(int *), m);
    if (!mat) return -909; // failed to allocate memory

    for (int i=0; i<m; i++)
    {
        mat[i] = calloc(sizeof(int), n);
        if (mat[i]==NULL)
        {
            for (int k=0; k<i; k++)
            {
                free(mat[k]);
            }
            free(mat);
            return -909;
        }
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == 0 || j==0) 
                mat[i][j]=1;
            else
                mat[i][j] = mat[i-1][j]+mat[i][j-1]; 
        }
    }

    int result = mat[m-1][n-1];
    for (int k=0; k<m; k++)
        free(mat[k]);
    free(mat);
    return result;
}