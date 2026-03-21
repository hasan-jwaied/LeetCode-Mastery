class Solution {
    public int deleteAndEarn(int[] nums) {
        int length = nums.length;
        if (length == 0) return 0;
        if (length == 1) return nums[0];

        int maximum = nums[0];
        for (int k=1; k<length; k++)
        {
            if (nums[k] > maximum)
                maximum = nums[k];
        }
        if (maximum == 0) return 0;

        int[] hash = new int[maximum+1];
        for (int i=0; i<length; i++)
            hash[nums[i]] += nums[i];

        int prev2 = hash[0];
        int prev1 = Math.max(hash[0], hash[1]);
        int curr = 0;

        for (int j=2; j<=maximum; j++)
        {
            curr = Math.max(prev2+hash[j], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}