class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left_mul=[]
        l_mul_num=1
        for i in nums:
            l_mul_num*=i
            left_mul.append(l_mul_num)
        
        print(left_mul)
        right_mul=[]
        r_mul_num=1

        for i in nums[::-1]:
            r_mul_num*=i
            right_mul=[r_mul_num]+right_mul
        
        print(right_mul)
        
        res_l=[]
        
        for i in range(len(nums)):
            if i==0:
                res_l.append(right_mul[i+1])

            elif i==len(nums)-1:
                res_l.append(left_mul[i-1])

            else:
                res_l.append(right_mul[i+1]*left_mul[i-1])

        return res_l


