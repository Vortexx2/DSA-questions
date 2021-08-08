"""
  @author Vortexx2
  Problem 236 - Lowest Common Ancestor

  Runtime - 64 ms
  Memory Usage - 25.2 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution:
  def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

    if not root: return None

    if root == p or root == q: return root

    left = self.lowestCommonAncestor(root.left, p, q)
    right = self.lowestCommonAncestor(root.right, p, q)

    if left and right:
      return root
    
    return left if left else right
