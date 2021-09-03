"""
  @author Vortexx2
  Problem 938 - Range Sum of BST

  Runtime - 209 ms
  Memory Usage - 22.4 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
    if not root:
      return 0

    total = 0

    if root.val < low:
      total += self.rangeSumBST(root.right, low, high)

    elif root.val > high:
      total += self.rangeSumBST(root.left, low, high)

    else:
      total = root.val + \
          self.rangeSumBST(root.left, low, high) + \
          self.rangeSumBST(root.right, low, high)

    return total
