class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        check_dict={}
        #row check
        for i in board:
            for j in i:
                if j in check_dict and j!=".":
                    return False
                else:
                    check_dict[j]=1
            check_dict={}
        #col check
        for k in range(0,9):
            for j in board:
                if j[k] in check_dict and j[k]!=".":
                    return False
                else:
                    check_dict[j[k]]=1
            check_dict={}
        #sub-box check
        for i in range(3):              # sub-box row index
            for l in range(3):          # sub-box column index
                check_dict = {}
                for j in board[3*i : 3*i + 3]:             # rows in this box
                    for k in range(3*l, 3*l + 3):          # cols in this box
                        val = j[k]
                        if val != ".":
                            if val in check_dict:
                                return False
                            check_dict[val] = 1
        return True