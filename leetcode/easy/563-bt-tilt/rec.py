"""
  @author Vortexx2
  Problem 563 - BT Tilt

  Runtime - 52 ms
  Memory Usage - 16.2 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def findTilt(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0

    self.tiltSum = 0
    self.helper(root)
    return self.tiltSum

  def helper(self, root: TreeNode) -> int:

    if not root:
      return 0

    a, b = self.helper(root.left), self.helper(root.right)
    self.tiltSum += abs(a - b)

    return a + b + root.val
