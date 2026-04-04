class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n =obstacles.size();
        vector<int> ans(n);
        vector<int> tails;

        for (int i=0; i<n; i++) {
            int obs = obstacles[i]; // curr obstacle length
            auto it = upper_bound(tails.begin(), tails.end(), obs);

            if (it == tails.end()) {
                tails.push_back(obs);
                ans[i] = tails.size();
            } else {
                *it = obs;
                ans[i] = distance(tails.begin(), it) + 1;
            }
        }
        return ans;
    }
};