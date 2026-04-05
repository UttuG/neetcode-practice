class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result=[]
        def generator(curr_pattern,open_count,close_count):
            if close_count==0:
                result.append(curr_pattern)
                return
            if close_count>open_count:
                generator(curr_pattern + ")",open_count,close_count-1)
            if open_count>0:
                generator(curr_pattern + "(",open_count-1,close_count)
            return
        
        generator("",n,n)

        return result