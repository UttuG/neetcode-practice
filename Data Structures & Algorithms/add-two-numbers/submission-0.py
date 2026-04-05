# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        new_head=ListNode()
        curr_node = new_head
        carry=0
        while l1 or l2 or carry>0:
            new_node = ListNode()
            if l1 and l2:
                new_val= (l1.val + l2.val + carry)%10
                carry = (l1.val + l2.val + carry)//10
                new_node.val = new_val
                curr_node.next = new_node
                curr_node = curr_node.next
                l1 = l1.next
                l2 = l2.next
            elif l1:
                new_val= (l1.val + carry)%10
                carry = (l1.val + carry)//10
                new_node.val = new_val
                curr_node.next = new_node
                curr_node = curr_node.next
                l1 = l1.next
            elif l2:
                new_val= (l2.val + carry)%10
                carry = (l2.val + carry)//10
                new_node.val = new_val
                curr_node.next = new_node
                curr_node = curr_node.next
                l2 = l2.next
            else:
                new_val= (carry)%10
                carry = (carry)//10
                new_node.val = new_val
                curr_node.next = new_node
                curr_node = curr_node.next
        return new_head.next
        