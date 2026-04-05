class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def permutation(set_):
            temp = []

            if not set_:
                return [[]]

            for i in set_:
                copy_ = set_.copy()
                copy_.remove(i)
                res_list = permutation(copy_)
                for j in res_list:
                    temp.append(j+[i])

            return temp
        return permutation(set(nums))
            
