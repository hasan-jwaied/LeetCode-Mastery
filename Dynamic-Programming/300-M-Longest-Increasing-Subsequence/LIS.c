int lengthOfLIS(int* nums, int numsSize) {
    int *temp = calloc(numSize, sizeof(int));
    if (!temp) return -909; // failed to allocate memory
    int result = 1;

    // init all values to 1
    for (int i=0; i<numsSize; i++) {
        temp[i] = 1;
    }

    for (int i=numSize-2; i>=0; i--) {
        for (int j=i+1; j<numSize; j++) {
            if (nums[i] < nums[j]) {
                OPT[i] = OPT[i]<1+OPT[j]?1+OPT[j]:OPT[i];
                if (result < OPT[i]) {
                    result = OPT[i];
                }
            }
        }
    }
    free(temp);
    return result;
}