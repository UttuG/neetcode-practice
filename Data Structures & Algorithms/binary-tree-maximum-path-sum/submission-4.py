# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def helper(node):
            if not node:
                return (0, float('-inf'))  # (branch_max, path_max)

            left_branch, left_path = helper(node.left)
            right_branch, right_path = helper(node.right)

            # Max path starting from this node down to one child (can include 0 if negative)
            branch_max = max(node.val, node.val + max(left_branch, right_branch))

            # Max path through this node (could include both children)
            full_path = node.val + max(left_branch, 0) + max(right_branch, 0)

            # Best path seen so far
            path_max = max(left_path, right_path, full_path)

            return (branch_max, path_max)

        return helper(root)[1]
    
