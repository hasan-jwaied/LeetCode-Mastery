class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        max_dist = 0
        x = 0
        y = 0
        my_set = {tuple(obs) for obs in obstacles}
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        curr_idx = 0
        
        for cmd in commands:
            if cmd == -1:
                curr_idx = (curr_idx + 1) % 4
            elif cmd == -2:
                curr_idx = (curr_idx - 1) % 4
            else:
                for _ in range(cmd):
                    next_x = x + directions[curr_idx][0]
                    next_y = y + directions[curr_idx][1]

                    if (next_x, next_y) in my_set:
                        break
                    
                    x = next_x
                    y = next_y
                    max_dist = max(max_dist, x*x + y*y)
        
        return max_dist