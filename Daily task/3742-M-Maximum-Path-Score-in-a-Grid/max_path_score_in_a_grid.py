class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        max_possible_cost = m + n - 2
        k = min(k, max_possible_cost)
        
        def get_cost(val):
            return 1 if val != 0 else 0

        prev_row = [[-float('inf')] * (k + 1) for _ in range(n)]
        
        for r in range(m - 1, -1, -1):
            curr_row = [[-float('inf')] * (k + 1) for _ in range(n)]
            
            for c in range(n - 1, -1, -1):
                val = grid[r][c]
                cost = get_cost(val)

                if r == m - 1 and c == n - 1:
                    for v in range(cost, k + 1):
                        curr_row[c][v] = val
                    continue
                
                can_move_right = (c + 1 < n)
                can_move_down = (r + 1 < m)
                
                for v in range(cost, k + 1):
                    rem_k = v - cost
                    best = -float('inf')
                    
                    if can_move_right:
                        best = curr_row[c + 1][rem_k]
                    if can_move_down:
                        down_score = prev_row[c][rem_k]
                        if down_score > best:
                            best = down_score
                            
                    if best != -float('inf'):
                        curr_row[c][v] = val + best
            
            prev_row = curr_row
            
        ans = prev_row[0][k]
        return ans if ans != -float('inf') else -1