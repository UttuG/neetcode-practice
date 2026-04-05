class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import defaultdict

        # Step 1: Count frequencies
        freq_map = defaultdict(int)
        for num in nums:
            freq_map[num] += 1

        # Step 2: Bucket sort based on frequencies
        # Buckets: index = frequency, value = list of numbers with that frequency
        n = len(nums)
        buckets = [[] for _ in range(n + 1)]
        for num, freq in freq_map.items():
            buckets[freq].append(num)

        # Step 3: Gather k most frequent elements from buckets
        result = []
        for freq in range(n, 0, -1):
            for num in buckets[freq]:
                result.append(num)
                if len(result) == k:
                    return result