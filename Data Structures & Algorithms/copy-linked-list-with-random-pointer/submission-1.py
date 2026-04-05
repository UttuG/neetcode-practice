"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        copy_dict={}
        curr_node = head
        while curr_node:
            copy = Node(curr_node.val)
            copy_dict[curr_node] = copy
            curr_node=curr_node.next
        
        curr_node = head
        while curr_node:
            if curr_node.next == None:
                copy_dict[curr_node].next = None
            else:
                copy_dict[curr_node].next = copy_dict[curr_node.next]
            
            if curr_node.random == None:
               copy_dict[curr_node].random = None
            else: 
                copy_dict[curr_node].random = copy_dict[curr_node.random]

            curr_node = curr_node.next

        return copy_dict[head] if head != None else None