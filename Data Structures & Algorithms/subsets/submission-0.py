class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def rec_sub(arr):
            #base case
            if len(arr) == 0:
                return [[]]

            #normal
            element = arr[0]
            res = rec_sub(arr[1:])
            temp = []
            for i in res:
                temp.append(i+[element])
                temp.append(i)
            
            return temp

        return rec_sub(nums)


        