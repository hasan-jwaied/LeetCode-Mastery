class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if (n <= 1) return n;

        unordered_map<int, int> seen;

        int result = 1;
        for (auto num: arr) {
            seen[num] = seen[num - difference] + 1;
            if (result < seen[num]) {
                result = seen[num];
            }
        }
        return result;
    }
};