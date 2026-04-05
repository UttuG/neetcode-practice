import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points = [[(x[0]**2+x[1]**2)**0.5,x] for x in points]

        heapq.heapify(points)

        result = []
        for i in range (0,k):
            result.append(heapq.heappop(points)[1])

        return result