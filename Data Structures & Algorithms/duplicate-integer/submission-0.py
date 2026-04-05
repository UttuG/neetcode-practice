class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique_set=set(nums)
        if len(unique_set)<len(nums):
            return True
        else:
            return False
         