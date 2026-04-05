class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        self.num_map={"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}

        def pattern(digits):
            if not digits:
                return [""]
            temp=[]
            for i in self.num_map[digits[0]]:
                temp_ = pattern(digits[1:])
                for j in temp_:
                    temp.append(i + j)
            return temp
        if not digits:
            return []
        else:
            return pattern(digits)