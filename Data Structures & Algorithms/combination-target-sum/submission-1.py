class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        def combinations(curr_sum,arr):
            temp = []
            for x,i in enumerate(arr):
                if curr_sum - i == 0:
                    temp.append([i])
                if curr_sum - i > 0:
                    res_ = combinations(curr_sum - i, arr[x:])
                    for j in res_:
                        temp.append([i] + j)
            return temp
        return combinations(target, nums)