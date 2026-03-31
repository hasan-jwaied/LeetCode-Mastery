int lengthOfLIS(int* nums, int numsSize) {
    int *temp = calloc(numsSize, sizeof(int));
    if (!temp) return -909; // failed to allocate memory
    int result = 1;

    // init all values to 1
    for (int i=0; i<numsSize; i++) {
        temp[i] = 1;
    }

    for (int i=numsSize-2; i>=0; i--) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i] < nums[j]) {
                temp[i] = temp[i]<1+temp[j]?1+temp[j]:temp[i];
                if (result < temp[i]) {
                    result = temp[i];
                }
            }
        }
    }
    free(temp);
    return result;
}