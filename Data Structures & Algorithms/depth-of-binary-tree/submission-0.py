# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
            
        sum_right = self.maxDepth(root.right) + 1
        sum_left = self.maxDepth(root.left)+ 1

        return max(sum_right,sum_left)
        