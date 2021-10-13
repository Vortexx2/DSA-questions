"""
  Problem 230 - Kth Smallest Element in BST

  Runtime - 62 ms
  Memory Usage - 17.8 MB
"""
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  count = 0

  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    if not root:
      return -1

    left = self.kthSmallest(root.left, k)

    if (left == -1):
      self.count += 1

      if (self.count == k):
        return root.val

      right = self.kthSmallest(root.right, k)

      if (right == -1):
        return -1

      else:
        return right

    else:
      return left
