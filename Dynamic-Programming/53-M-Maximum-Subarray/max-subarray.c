int maximum (int a, int b)
{
    return a>b?a:b;
}
int maxSubArray(int* nums, int numsSize) {
    int best=nums[0], sum = nums[0];
    for (int k=1; k<numsSize; k++)
    {
        sum = maximum(nums[k], sum+nums[k]);
        best = maximum(best, sum);
    }
    return best;
}