class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l_p = 0
        r_p = len(nums) - 1
        
        while l_p <= r_p:
            mid = (l_p + r_p) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l_p = mid + 1
            else:
                r_p = mid - 1
        
        return -1
        