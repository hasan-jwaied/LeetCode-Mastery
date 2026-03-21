class Solution {
    public int uniquePaths(int m, int n) {
        if (m<=0 || n<=0) return -909; // invalid inputs!

        // init the first row with ones:
        int[] arr = new int[n];
        for (int i=0; i<n; i++)
            arr[i] = 1;

        for (int i=1; i<m; i++)
        {
            for (int j=1; j<n; j++)
            {
                arr[j] = arr[j] + arr[j-1];
            }
        }
        return arr[n-1];
    }
}