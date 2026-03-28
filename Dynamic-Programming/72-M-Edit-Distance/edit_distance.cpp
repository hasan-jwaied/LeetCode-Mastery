class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        if (w1 == 0) return w2;
        if (w2 == 0) return w1;

        vector<vector<int>> OPT(w2+1, vector<int>(w1+1, 0));

        for (int i=0; i<w1+1; i++) {
            OPT[0][i] = i;
        }

        for (int j=0; j<w2+1; j++) {
            OPT[j][0] = j;
        }

        for (int i=1; i<w2+1; i++) {
            for (int j=1; j<w1+1; j++) {
                if (word1[j-1] == word2[i-1]) {
                    OPT[i][j] = OPT[i-1][j-1];
                } else {
                    OPT[i][j] = 1 + min({OPT[i][j-1], OPT[i-1][j-1], OPT[i-1][j]});
                }
            }
        }
        return OPT[w2][w1];
    }
};