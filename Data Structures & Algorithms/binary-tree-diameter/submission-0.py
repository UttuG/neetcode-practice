# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        self.diameter = 0  # Store the diameter

        def maxDepth(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            left_depth = maxDepth(node.left)
            right_depth = maxDepth(node.right)

            # Update the diameter at each node
            self.diameter = max(self.diameter, left_depth + right_depth)

            return max(left_depth, right_depth) + 1

        maxDepth(root)

        return self.diameter

        
