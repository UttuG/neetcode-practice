# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = [0]
        target = [0]

        def inorder(node, count, target):
            if (not node.right) and (not node.left):
                count[0]+=1
                if count[0]<=k:
                    target[0] = node.val
                    return None
            if node.left:
                inorder(node.left, count, target)
            count[0]+=1
            if count[0]<=k:
                target[0] = node.val
            if node.right:
                inorder(node.right, count, target)
            
        inorder(root, count, target)

        return target[0]

            