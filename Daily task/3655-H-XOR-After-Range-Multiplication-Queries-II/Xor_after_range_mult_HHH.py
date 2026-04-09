class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        BLOCK_SIZE = int(sqrt(n)) + 1
        
        light_queries = defaultdict(list)
        inv_cache = {}
        
        for li, ri, ki, vi in queries:
            if ki >= BLOCK_SIZE:
                for j in range(li, ri + 1, ki):
                    nums[j] = (nums[j] * vi) % MOD
            else:
                light_queries[ki].append((li, ri, vi))
                
        for ki, q_list in light_queries.items():
            
            lazy = [1] * (n + ki + 1)
            
            for li, ri, vi in q_list:
                lazy[li] = (lazy[li] * vi) % MOD
                
                steps = (ri - li) // ki
                first_out = li + (steps + 1) * ki
                
                if vi not in inv_cache:
                    inv_cache[vi] = pow(vi, MOD - 2, MOD)
                    
                lazy[first_out] = (lazy[first_out] * inv_cache[vi]) % MOD
            
            for i in range(n):
                if i >= ki and lazy[i - ki] != 1:
                    lazy[i] = (lazy[i] * lazy[i - ki]) % MOD
                    
                if lazy[i] != 1:
                    nums[i] = (nums[i] * lazy[i]) % MOD
                    
        result = 0
        for num in nums:
            result ^= num
            
        return result