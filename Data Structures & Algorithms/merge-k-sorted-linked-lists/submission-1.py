# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        import heapq
        #get the heads of all the lists in an array and sort them based on val (only once)

        #now remove the head from the 0th index in the array and then fit in its successor in the sorted array using binary search
        #repeat
        heap = []
        for idx, node in enumerate(lists):
            heapq.heappush(heap,(node.val,idx,node))
        
        dummy_head = ListNode()
        curr_node = dummy_head

        while len(heap)>0:
            val, idx, node = heapq.heappop(heap)
            curr_node.next = node
            curr_node = curr_node.next
            if node.next != None:
                heapq.heappush(heap,(node.next.val, idx, node.next))
        
        return dummy_head.next


        
