class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        nums.sort()
        prev_size = 0

        for i, x in enumerate(nums):
            # If current is a duplicate, only extend the subsets
            # created in the previous step
            start = prev_size if i > 0 and x == nums[i - 1] else 0
            prev_size = len(result)
            
            result_ = []
            for j in range(start, len(result)):
                result_.append(result[j] + [x])
            result += result_
        
        return result