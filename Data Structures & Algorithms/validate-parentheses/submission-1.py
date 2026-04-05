from collections import deque

class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()
        append_set={'(','{','['}
        pop_set={'}',')',']'}
        relation_dict={'}':'{',']':'[',')':'('}
        
        for i in s:
            if i in append_set:
                stack.append(i)
            else:
                try:
                    return_val=stack.pop()
                    if return_val!=relation_dict[i]:
                        return False
                except:
                    return False
        if len(stack)!=0:
            return False
        return True