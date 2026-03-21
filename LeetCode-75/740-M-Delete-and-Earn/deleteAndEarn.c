int maximum(int a, int b)
{
    return a>b?a:b;
}

int deleteAndEarn(int* nums, int numsSize) {
    // make sure valid inputs.
    // find the maximum value in the array.
    // build hash-frequ. table for the values in the table.
    // store in this table: in each index the value: i*frequ[i]

    // solve it as a dynamic-problem.
        // - for each i, decide if you want to take it:
            // -if yes: you can't take the adjacent values
            // -if no:take until i-1 value
            // take the maximum values of the two.
        // at the end take the maximum value in the array you built.
    
    // -> we will sovle the optimized ver, with 3 vars.
    // free
    // return

    if (!nums || numsSize <=0) return 0; // invalid inputs

    int max_nums = nums[0];
    for (int i=1; i<numsSize; i++)
    {
        if (nums[i] > max_nums)
            max_nums = nums[i];
    }
    if (max_nums == 0) return 0; // edge case

    int* hash = calloc(sizeof(int), (max_nums+1));
    if (!hash)
        return -909; // failed to allocate memory
    for (int k=0; k<numsSize; k++)
    {
        hash[nums[k]] += nums[k];
    }

    // solve dynamically.
    // for each value we have to decide if to take it or not.
    // if we take it, we can't take the adjacent values,
    // else, we take up to the prev. depoisted value, then we take the maximum of these 
    // two choices:
    int prev2 = hash[0];
    int prev1 = maximum(hash[0], hash[1]);
    int curr = 0;
    for (int j=2; j<=max_nums; j++)
    {
        curr = maximum(hash[j]+prev2, prev1);
        prev2=prev1;
        prev1=curr;
    }
    free(hash);
    return prev1;
}