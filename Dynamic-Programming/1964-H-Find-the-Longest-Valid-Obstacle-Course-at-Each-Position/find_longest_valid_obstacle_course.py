from bisect import bisect_right
class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: list[int]) -> list[int]:
        ans: list[int] = []
        tails: list[int]= []
        
        
        for obs in obstacles:
            idx = bisect_right(tails, obs)
            
            if idx == len(tails):
                tails.append(obs)
            else:
                tails[idx] = obs
            
            ans.append(idx + 1)
        return ans