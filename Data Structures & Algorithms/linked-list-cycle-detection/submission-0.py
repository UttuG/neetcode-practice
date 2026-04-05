# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        pointer_1= head
        pointer_2= head

        while pointer_2 and pointer_1:
            pointer_1=pointer_1.next

            pointer_2=pointer_2.next
            if not pointer_2:
                return False 
            else:
                pointer_2=pointer_2.next

            if pointer_1 ==pointer_2:
                return True
        return False
        