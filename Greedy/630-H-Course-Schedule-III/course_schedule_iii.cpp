# include <vector>
# include <algorithm>
# include <queue>

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>&a, const vector<int>&b) {return a<b;});
        priority_queue<int> maxheap;

        int total_time = 0;
        for (const auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            maxheap.push(duration);
            total_time += duration;

            if (total_time > lastDay) {
                total -= maxheap.top();
                maxheap.pop();
            }
            
        }
        return maxheap.size();
    }
};