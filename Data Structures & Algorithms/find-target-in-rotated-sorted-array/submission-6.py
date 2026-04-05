class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left=0
        right=len(nums)-1

        while left <= right:
            mid = (left + right)//2
            
            if nums[mid]==target:
                return mid

            if nums[left]<=nums[mid]:
                #left section sorted
                if nums[left]<=target<nums[mid]:
                    #target in left section
                    right = mid - 1
                else:
                    #target not in left section
                    left = mid + 1
            
            else:
                #right section sorted
                if nums[mid]<target<=nums[right]:
                    #target in right section
                    left = mid + 1
                else:
                    #target in left section
                    right = mid - 1
        return -1
