"""
  @author Vortexx2
  Problem 617 - Merge Two BTs

  Runtime - 92 ms
  Memory Usage - 15.3 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root1 and not root2:
      return None

    if not root1:
      return TreeNode(root2.val, self.mergeTrees(None, root2.left), self.mergeTrees(None, root2.right))

    if not root2:
      return TreeNode(root1.val, self.mergeTrees(root1.left, None), self.mergeTrees(root1.right, None))

    return TreeNode(root1.val + root2.val, self.mergeTrees(root1.left, root2.left), self.mergeTrees(root1.right, root2.right))
