import heapq as hq
class Solution:
    def scheduleCourse(self, courses: list[list[int]]) -> int:
        courses.sort(key=lambda x:x[1]) # sort by lastDay (..<=.. <=..)

        total_time = 0
        my_lst: list[int] = []

        for course in courses:
            hq.heappush(my_lst, -course[0])
            total_time += course[0]
            if total_time > course[1]:
                total_time += hq.heappop(my_lst)
        return len(my_lst)