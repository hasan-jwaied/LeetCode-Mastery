// first solution, O(n) space complixity
int minimum (int a, int b)
{
    return a<b?a:b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    if (!cost || costSize<=0) return -77; // invalid inputs!

    int* f = calloc(sizeof(int), (costSize+1));
    if (!f) return -909; // failed to allocate memory

    // no need to set f[0] = f[1] = 0, we used calloc()...
    for (int k=2; k<=costSize; k++)
    {
        f[k] = minimum(f[k-1]+cost[k-1], f[k-2]+cost[k-2]);   
    }

    int result = f[costSize];
    free(f);
    return result;
}

// OPTIMIZED (O(1) SPCAE COMP.)

int minCostClimbingStairs(int* cost, int costSize) {
    if (!cost || costSize<=0) return -99; // invalid input
    int prev1 = 0;
    int prev2 = 0;

    for (int k=2; k<=costSize; k++)
    {
        int curr = minimum(prev1+cost[k-1], prev2+cost[k-2]);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}