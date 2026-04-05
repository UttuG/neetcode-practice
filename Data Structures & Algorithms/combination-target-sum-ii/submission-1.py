class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def combinations(curr_sum,arr):
            if len(arr)==0:
                return []
            temp = []
            for x,i in enumerate(arr):
                if i == arr[x-1] and  x > 0:
                    continue
                if curr_sum - i == 0:
                    temp.append([i])
                if curr_sum - i > 0:
                    res_ = combinations(curr_sum - i, arr[x+1:])
                    for j in res_:
                        temp.append([i] + j)
            return temp
        candidates.sort()
        return combinations(target, candidates)