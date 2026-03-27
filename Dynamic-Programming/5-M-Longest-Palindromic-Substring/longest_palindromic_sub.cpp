#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int max_len = 1;
        int start_idx = 0;

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start_idx = i;
                max_len = 2;
            }
        }

        for (int L = 3; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1; 

                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    
                    if (L > max_len) {
                        start_idx = i;
                        max_len = L;
                    }
                }
            }
        }
        return s.substr(start_idx, max_len);
    }
};