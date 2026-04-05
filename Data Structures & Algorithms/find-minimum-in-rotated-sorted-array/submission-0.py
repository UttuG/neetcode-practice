class Solution:
    def findMin(self, nums: List[int]) -> int:
        left_i=0
        right_i=len(nums)-1
        mid = (right_i+left_i)//2
        
        while True:
            if nums[left_i]<nums[mid] and nums[mid]<nums[right_i]:
                return nums[left_i]
                break
            if nums[left_i] == nums[mid] or nums[mid]==nums[right_i]:
                return min(nums[left_i],nums[mid],nums[right_i])
                break
            if nums[left_i]<nums[mid]:
                left_i = mid
                mid = (right_i+left_i)//2
                continue
            if nums[mid]<nums[right_i]:
                right_i = mid
                mid = (right_i+left_i)//2
                continue


            
        