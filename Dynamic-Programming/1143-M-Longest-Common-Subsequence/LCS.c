int max(int a, int b) {
    return a>b?a:b;
}

int longestCommonSubsequence(char* text1, char* text2) {
    int t1 = strlen(text1);
    int t2 = strlen(text2);
    if (t1==0 || t2==0)
        return 0;

    int** OPT = malloc(sizeof(int *) * (t2+1));
    if (!OPT) return -909; // faled to allocate memory

    for (int i=0; i<t2+1; i++) {
        OPT[i] = calloc(sizeof(int), t1+1);
        if (!OPT[i]) {
            for (int k=0; k<i; k++) {
                free(OPT[k]);
            }
            free(OPT);
            return -909; // failed to allocate memory
        }
    }

    for (int i=1; i<t2+1; i++) {
        for (int j=1; j<t1+1; j++) {
            if (text1[j-1] == text2[i-1])
                OPT[i][j] = 1 + OPT[i-1][j-1];
            else
                OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);
        }
    }
    int result = OPT[t2][t1];
    for (int i=0; i<t2+1; i++) {
        free(OPT[i]);
    }
    free(OPT);
    return result;
}