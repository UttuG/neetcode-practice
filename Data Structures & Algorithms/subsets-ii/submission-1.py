class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res= [[]]
        previous_ = 0
        for i,x in enumerate(nums):
            if i>0 and x == nums[i-1]:
                start_ = previous_
            else:
                start_ = 0
            res_ = res.copy()
            for k in res[start_:]:
                res_.append(k + [x])
            previous_ = len(res)
            res = res_
        return res
        