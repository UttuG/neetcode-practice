# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def get_depth(node):
            # If the node is null, return 0 as its depth
            if not node:
                return 0

            # Get the depth of the left and right subtrees
            left_depth = get_depth(node.left)
            right_depth = get_depth(node.right)

            # If one of the subtrees is unbalanced (depth difference > 1), return -1
            if left_depth == -1 or right_depth == -1 or abs(left_depth - right_depth) > 1:
                return -1

            # Return the depth of the current node
            return max(left_depth, right_depth) + 1
        
        # If the result of get_depth is -1, the tree is unbalanced
        return get_depth(root) != -1
            



        