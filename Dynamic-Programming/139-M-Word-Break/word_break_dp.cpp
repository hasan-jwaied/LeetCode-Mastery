class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        if (n==0) return true;
        unordered_set<string> my_set(wordDict.begin(), wordDict.end());
        vector<bool> OPT(n+1, false);
        OPT[0] = true;

        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (OPT[j]==true && my_set.count(s.substr(j, i-j))) {
                    OPT[i] = true;
                    break;
                }
            }
        }
        return OPT[n];
    }
};