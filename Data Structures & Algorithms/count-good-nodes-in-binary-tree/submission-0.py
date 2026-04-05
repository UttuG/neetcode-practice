# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def checkgood(val, max_):
            if val<max_:
                return 0
            else:
                return 1
        
        def sumgood(node,max_):
            if not node:
                return 0
            res = checkgood(node.val, max_)
            if res:
                return res + sumgood(node.right, node.val) + sumgood(node.left, node.val)
            else:
                return res + sumgood(node.right, max_) + sumgood(node.left, max_)
        
        return 1 + sumgood(root.left,root.val) + sumgood(root.right, root.val)

        