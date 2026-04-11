import heapq as hq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: list[list[int]]) -> int:
        stations.append([target, 0])
        stops = 0
        curr_fuel = startFuel
        max_heap: list[int] = []
        
        for position, fuel in stations:
            while curr_fuel < position:
                if not max_heap:
                    return -1
                curr_fuel -= hq.heappop(max_heap)
                stops += 1
            hq.heappush(max_heap, -fuel)
        return stops