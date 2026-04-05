# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validsubtree(node):
            # Base case: leaf node
            if not node.left and not node.right:
                return (True, node.val, node.val)

            # Only right child exists
            if not node.left:
                bool_r, branch_rmax, branch_rmin = validsubtree(node.right)
                if bool_r and branch_rmin > node.val:
                    return (True, max(branch_rmax, node.val), node.val)
                else:
                    return (False, -1, -1)

            # Only left child exists
            if not node.right:
                bool_l, branch_lmax, branch_lmin = validsubtree(node.left)
                if bool_l and branch_lmax < node.val:
                    return (True, node.val, min(branch_lmin, node.val))
                else:
                    return (False, -1, -1)

            # Both children exist
            bool_l, branch_lmax, branch_lmin = validsubtree(node.left)
            bool_r, branch_rmax, branch_rmin = validsubtree(node.right)

            if bool_l and bool_r and branch_lmax < node.val and branch_rmin > node.val:
                return (True, max(branch_rmax, node.val), min(branch_lmin, node.val))
            else:
                return (False, -1, -1)

        return validsubtree(root)[0]
        