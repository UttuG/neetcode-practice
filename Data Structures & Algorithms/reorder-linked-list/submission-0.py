# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        #first run to get the list length to determine the center
        count=1
        curr_node=head
        while curr_node.next!=None:
            curr_node=curr_node.next
            count+=1
        
        if count%2==0:
            stop_i=count//2
        else:
            stop_i=count//2 + 1
        
        #splitting the list in two
        count=1
        curr_node = head
        while count!=stop_i:
            curr_node=curr_node.next
            count+=1
        head_l2=curr_node.next
        curr_node.next = None

        #reversing the second list to merge
        prev = None
        curr = head_l2
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        head_l2 = prev

        #merging
        curr_l1=head
        curr_l2=head_l2

        while curr_l1 and curr_l2:
            l1_next=curr_l1.next
            l2_next= curr_l2.next
            curr_l1.next = curr_l2
            curr_l2.next = l1_next
            curr_l1 = l1_next
            curr_l2 = l2_next


