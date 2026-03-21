int maximum (int a, int b)
{
    return a>b?a:b;
}

int rob(int* nums, int numsSize) {
    if (!nums || numsSize<=0) return -99; // invalid inputs
    if (numsSize == 1) return nums[0];
    
    int* opt = calloc(sizeof(int), numsSize);
    if (!opt) return -909; // failed to allocate memory

    opt[0] = nums[0];
    opt[1] = maximum(nums[0], nums[1]);

    for (int i=2; i<numsSize; i++)
    {
        opt[i] = maximum(nums[i]+opt[i-2], opt[i-1]);
    }

    int result = opt[numsSize-1];
    free(opt);
    return result;
}

// OPTIMIZED O(1) SPACE COMPLX.

int rob(int* nums, int numsSize) {
    if (!nums || numsSize<=0) return -99; // invalid inputs
    if (numsSize == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = maximum(nums[0], nums[1]);
    int curr = 0;
    for (int i=2; i<numsSize; i++)
    {
        curr = maximum(nums[i]+prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}