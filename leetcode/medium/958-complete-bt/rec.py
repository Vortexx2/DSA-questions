"""
  Problem 958 - Check for completeness of BT

  Runtime - 28 ms
  Memory Usage - 14.2 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
    self.nodeCount = self.countNodes(root)

    return self.completeHelper(root, 0)

  def completeHelper(self, root: Optional[TreeNode], idx: int) -> bool:
    if not root:
      return True

    if idx >= self.nodeCount:
      return False

    return self.completeHelper(root.left, 2 * idx + 1) and self.completeHelper(root.right, 2 * idx + 2)

  def countNodes(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0

    return 1 + self.countNodes(root.left) + self.countNodes(root.right)
