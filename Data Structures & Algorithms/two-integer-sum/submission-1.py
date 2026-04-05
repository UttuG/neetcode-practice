class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict_nums={}

        for i,x in enumerate(nums):
            dict_nums[x]=i
        
        for i,x in enumerate(nums):
            if target-x in dict_nums:
                if dict_nums[target-x]!=i:
                    return [i,dict_nums[target-x]]
        
        