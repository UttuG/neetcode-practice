import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap  = []
        self.k = k
        for i,x in enumerate(nums):
            if i<k:
                heapq.heappush(self.heap, x)
            else:
                if x > self.heap[0]:
                    heapq.heappop(self.heap)
                    heapq.heappush(self.heap, x)

    def add(self, val: int) -> int:
        if len(self.heap)<self.k:
            heapq.heappush(self.heap, val)
            return self.heap[0]
            
        if val > self.heap[0]:
            heapq.heappop(self.heap)
            heapq.heappush(self.heap, val)
            return self.heap[0]

        return self.heap[0]
