class Solution:
    def survivedRobotsHealths(self, positions:list[int], healths:list[int], directions:str)->list[int]:
        n = len(positions)
        my_lst:list[list[Any]] = [[] for _ in range(n)]
        for i in range(n):
            my_lst[i].append(positions[i])
            my_lst[i].append(healths[i])
            my_lst[i].append(directions[i])
            my_lst[i].append(i) # original index
        my_lst.sort(key=lambda x:x[0])

        stack = []
        for element in my_lst:
            if element[2] == 'R':
                stack.append(element)
            else:
                is_alive = 1
                while stack and stack[-1][2] == 'R':
                    if element[1] < stack[-1][1]:
                        stack[-1][1] -= 1
                        is_alive = 0
                        break
                    elif element[1] > stack[-1][1]:
                        element[1] -= 1
                        stack.pop()
                    else:
                        stack.pop()
                        is_alive = 0
                        break
                if is_alive:
                    stack.append(element)
        stack.sort(key=lambda x:x[3])
        result = []
        for elem in stack:
            result.append(elem[1])
        
        return result