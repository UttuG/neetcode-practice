# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        l=[]
        
        def append_list(node, depth, l):
            if len(l)-1>=depth:
                l[depth].append(node.val)
            else:
                l.append([node.val])
        
        def recursive_looper(node, depth, l):
            append_list(node,depth,l)
            if node.left:
                recursive_looper(node.left,depth+1,l)
            if node.right:
                recursive_looper(node.right,depth+1,l)
            
            return l
        
        if root: 
            return recursive_looper(root,0,l)
        else:
            return []

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        final_l= []
        for i in self.levelOrder(root):
            final_l.append(i[-1])
        
        return final_l
