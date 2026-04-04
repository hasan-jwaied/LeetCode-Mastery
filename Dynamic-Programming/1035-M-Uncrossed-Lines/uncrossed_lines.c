int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums2Size;
    int n = nums1Size;

    int** OPT = malloc(sizeof(int *) * (m+1));
    if (!OPT) return -909; // failed to allocate memory
    for (int i=0; i<m+1; i++) {
        OPT[i] = calloc(n+1, sizeof(int));
        if (!OPT[i]) {
            for (int k=0; k<i; k++) {
                free(OPT[k]);
            }
            free(OPT);
            return -909;
        }
    }

    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (nums1[j-1] == nums2[i-1]) {
                OPT[i][j] = 1 + OPT[i-1][j-1];
            } else {
                OPT[i][j] = OPT[i-1][j] > OPT[i][j-1]?OPT[i-1][j]:OPT[i][j-1];
            }
        }
    }

    int result = OPT[m][n];
    for (int i=0; i<m+1; i++) {
        free(OPT[i]);
    }
    free(OPT);
    return result;
}