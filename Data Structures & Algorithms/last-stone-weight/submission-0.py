import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-1*x for x in stones]
        heapq.heapify(stones)
        heap = stones
        while len(heap) > 1:
            max_1 = abs(heapq.heappop(heap))
            # print(max_1)
            max_2 = abs(heapq.heappop(heap))
            # print(max_2)

            if max_1 != max_2:
                heapq.heappush(heap,-1*(max_1-max_2))
            
        if len(heap)==1:
            return abs(heap[0])
        else:
            return 0