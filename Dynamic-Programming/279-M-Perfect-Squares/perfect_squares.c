class Solution {
public:
    int numSquares(int n) {
        vector<int> OPT(n+1, n);
        OPT[0] = 0;

        for (int i=1; i<n+1; i++) {
            for (int j=1; j<i+1; j++) {
                if (i-(j*j) < 0)
                    break;
                OPT[i] = min(OPT[i], 1+OPT[i-(j*j)]);
            }
        }
        return OPT[n];
    }
};