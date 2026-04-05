import heapq
from collections import Counter, deque
from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        
        # Max heap of task frequencies (negative values)
        heap = [(-cnt, task) for task, cnt in freq.items()]
        heapq.heapify(heap)

        # Cooldown queue: (ready_time, -count, task)
        cooldown = deque()

        time = 0
        while heap or cooldown:
            time += 1

            if heap:
                count, task = heapq.heappop(heap)
                count += 1  # decrease count (less negative)

                if count < 0:
                    cooldown.append((time + n, count, task))  # task will be ready at time + n

            # Check if any task is coming out of cooldown
            if cooldown and cooldown[0][0] == time:
                ready_time, count, task = cooldown.popleft()
                heapq.heappush(heap, (count, task))

        return time