class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        factory.sort(key=lambda x:x[0]) # sort the factories positions
        robot.sort()
        factory_slots = []
        for fact in factory:
            temp = [fact[0]] * fact[1]
            factory_slots.extend(temp)
        
        n = len(robot)
        m = len(factory_slots)

        OPT = [[0] * (m+1) for _ in range(n+1)]
        for i in range(1, n+1):
            OPT[i][0] = float('inf')
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                OPT[i][j] = min(OPT[i][j-1], OPT[i-1][j-1] + abs(robot[i-1] - factory_slots[j-1]))
        
        return OPT[n][m]