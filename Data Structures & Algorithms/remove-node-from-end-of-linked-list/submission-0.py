# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # First pass: count the nodes
        length = 0
        node = head
        while node:
            length += 1
            node = node.next

        # If we need to remove the head itself (n == length), just skip it
        if n == length:
            return head.next

        # Otherwise, find the predecessor of the node to remove:
        # it’s at position (length - n) using 1-based indexing
        # e.g. length=5, n=2 → remove 4th node → predecessor is 3rd
        steps_to_predecessor = length - n
        prev = head
        for _ in range(1, steps_to_predecessor):
            prev = prev.next

        # Skip over the target node
        prev.next = prev.next.next
        return head
