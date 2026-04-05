# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        smaller_node = min(p.val,q.val)
        larger_node = max(p.val,q.val)
        curr_node = root
        while curr_node:
            if smaller_node <= curr_node.val <= larger_node:
                return curr_node
            else:
                if curr_node.val>=larger_node:
                    curr_node = curr_node.left
                else:
                    curr_node = curr_node.right