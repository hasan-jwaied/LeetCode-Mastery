class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        m = len(triangle)
        for i in range(m-2, -1, -1):
            for j in range(0, len(triangle[i])):
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
        return triangle[0][0]