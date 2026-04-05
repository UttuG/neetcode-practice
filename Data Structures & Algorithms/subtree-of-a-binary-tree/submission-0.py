# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        from collections import deque

        def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
            if not p and not q:  # Both trees are empty
                return True
            if not p or not q:  # One tree is empty, the other is not
                return False
            
            # Compare values of current nodes
            if p.val != q.val:
                return False
            
            # Recursively compare left and right subtrees
            return isSameTree(p.left, q.left) and isSameTree(p.right, q.right)
        
        node_queue = deque([root])
        #pop the left most node, check if isSameTree, if not, add children and iterate:
        while len(node_queue)>0:
            #check
            pop_node = node_queue.popleft()
            if isSameTree (pop_node,subRoot):
                return True
            if pop_node.left:
                node_queue.append(pop_node.left)
            if pop_node.right:
                node_queue.append(pop_node.right)
        
        return False

