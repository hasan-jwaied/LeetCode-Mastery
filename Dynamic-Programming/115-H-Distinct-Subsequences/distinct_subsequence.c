int numDistinct(char* s, char* t) {
    size_t m = strlen(t);
    size_t n = strlen(s);

    size_t** OPT = malloc(sizeof(size_t *) * (m+1));
    for (size_t i=0; i<m+1; i++) {
        OPT[i] = calloc(n+1, sizeof(size_t));
        if (!OPT[i]) {
            for (size_t k=0; k<i; k++) {
                free(OPT[k]);
            }
            free(OPT);
            return -909; // failed to allocate memory
        }
    }
    for (size_t i=0; i<n+1; i++) 
        OPT[0][i] = 1;

    for (size_t i=1; i<m+1; i++) {
        for (size_t j=1; j<n+1; j++) {
            if (i>j) continue;

            if (s[j-1] == t[i-1])
                OPT[i][j] = OPT[i-1][j-1] + OPT[i][j-1];
            else
                OPT[i][j] = OPT[i][j-1];
        }
    }

    int result = OPT[m][n];

    for (size_t i=0; i<=m; i++)
        free(OPT[i]);
    free(OPT);
    return result;
}