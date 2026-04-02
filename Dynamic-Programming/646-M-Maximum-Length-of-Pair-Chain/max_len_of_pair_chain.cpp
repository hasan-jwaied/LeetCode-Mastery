class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if (n <= 1) return n;

        sort(pairs.begin(), pairs.end());
        vector<int> OPT(n, 1);

        int result = 0;
        for (int i=n-2; i>=0; i--) {
            for (int j=1+i; j<n; j++) {
                if (pairs[i][1] < pairs[j][0]) {
                    OPT[i] = max(OPT[i], OPT[j] + 1);
                    if (result < OPT[i])
                        result = OPT[i];
                }
            }
        }
        return result;
    }
};