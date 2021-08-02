"""
  @author Vortexx2
  Problem 101 - Symmetric Tree

  Runtime - 24 ms
  Memory Usage - 14.3 MB
"""
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSymmetric(self, root: TreeNode) -> bool:
    if not root:
      return False

    return self.helper(root.left, root.right)

  def helper(self, p: TreeNode, q: TreeNode) -> bool:

    if not p and not q:
      return True

    if not p or not q:
      return False

    if p.val != q.val:
      return False

    return self.helper(p.left, q.right) and self.helper(p.right, q.left)