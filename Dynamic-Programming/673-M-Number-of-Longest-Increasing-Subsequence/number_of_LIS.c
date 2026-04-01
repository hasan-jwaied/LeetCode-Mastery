int findNumberOfLIS(int* nums, int n) {
    if (n <= 1) return n;

    int* OPT = calloc(n, sizeof(int));
    if (!OPT) return -909; // failed to allocate mem.
    int* count = calloc(n, sizeof(int));
    if (!count) return -909;

    for (int i=0; i<n; i++) {
        OPT[i] = 1;
        count[i] = 1;
    }

    for (int i=n-2; i>=0; i--) {
        for (int j=i+1; j<n; j++) {
            if (nums[i] < nums[j]) {
                if (OPT[i] < 1+OPT[j]) {
                    OPT[i] = OPT[j] + 1;
                    count[i] = count[j];
                }
                else if (OPT[i] == 1+OPT[j]) {
                    count[i] += count[j];
                }
            } 
        }
    }
    global_max = OPT[0];
    for (int i=1; i<n; i++) {
        if (OPT[i]>global_max)
            global_max = OPT[i];
    }

    int result = 0;
    for (int j=0; j<n; j++) {
        if (OPT[j] == global_max)
            result += count[j];
    }
    
    free(OPT);
    free(count);
    return result;
}