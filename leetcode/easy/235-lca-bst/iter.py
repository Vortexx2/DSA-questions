"""
  @author Vortexx2
  Problem 235 - LCA of BST

  Runtime - 76 ms
  Memory Usage - 18.1 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution:
  def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    minNode, maxNode = None, None
    if p.val < q.val:
      minNode, maxNode = p, q
    else:
      minNode, maxNode = q, p

    while root.val < minNode.val or root.val > maxNode.val:
      if root.val < minNode.val:
        root = root.right

      else:
        root = root.left

    return root
