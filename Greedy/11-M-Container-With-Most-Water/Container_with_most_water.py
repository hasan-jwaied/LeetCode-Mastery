class Solution:
    def maxArea(self, height: list[int]) -> int:
        start = 0
        end = len(height) - 1
        result = 0
        while start < end:
            temp = (end-start) * min(height[start], height[end])
            if temp > result:
                result = temp
            if height[start] < height[end]:
                start += 1
            else:
                end -= 1
        return result