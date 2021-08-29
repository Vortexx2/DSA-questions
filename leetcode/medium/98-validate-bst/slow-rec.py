"""
  @author Vortexx2
  Problem 98 - Validate BST

  Runtime - 124 ms O(n^2)
  Memory Usage - 17 MB O(n^2)
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isValidBST(self, root: Optional[TreeNode]) -> bool:
    if not root:
      return True
    self.val = root.val

    if (not self.isLesser(root.left) or not self.isGreater(root.right)):
      return False

    return self.isValidBST(root.left) and self.isValidBST(root.right)

  def isLesser(self, root: TreeNode):
    if not root:
      return True

    return root.val < self.val and self.isLesser(root.left) and self.isLesser(root.right)

  def isGreater(self, root: TreeNode):
    if not root:
      return True

    return root.val > self.val and self.isGreater(root.left) and self.isGreater(root.right)
