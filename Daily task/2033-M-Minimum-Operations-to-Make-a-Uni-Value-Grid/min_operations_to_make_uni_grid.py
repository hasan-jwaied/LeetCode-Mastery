class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        m = len(grid)
        n = len(grid[0])

        result = 0
        checkReminder = grid[0][0] % x
        tempList = []
        for i in range(m):
            for j in range(n):
                if grid[i][j]%x != checkReminder:
                    return -1
                tempList.append(grid[i][j])
        tempList.sort()
        lenTemp = len(tempList)
        mid = tempList[lenTemp//2]

        for i in range(lenTemp):
            result += abs(mid - tempList[i]) // x

        return result