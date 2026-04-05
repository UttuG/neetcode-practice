# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        if not root:
            return None
        
        node = root
        node_left = node.left
        node_right = node.right

        #invert the right and left
        node.right = node_left
        node.left = node_right

        #recursively the right and left
        if node.right:
            self.invertTree(node.right)
        if node.left:
            self.invertTree(node.left)
        
        return root
