"""
  @author Vortexx2
  Problem 1339 - Max Prod of Splitted BT

  Runtime - 400 ms
  Memory Usage - 69 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def maxProduct(self, root: Optional[TreeNode]) -> int:
    self.res = 0
    self.total = 0
    self.totalTreeSum(root)
    self.sumUnder(root)
    return int(self.res % (1e9 + 7))

  def totalTreeSum(self, root: TreeNode) -> None:
    if not root:
      return 0

    self.total += root.val
    self.totalTreeSum(root.left) and self.totalTreeSum(root.right)

  def sumUnder(self, root: TreeNode) -> int:
    if not root:
      return 0

    sumUnderLeft, sumUnderRight = self.sumUnder(
        root.left), self.sumUnder(root.right)
    self.res = max(self.res, (self.total - sumUnderLeft) *
                   sumUnderLeft, (self.total - sumUnderRight) * sumUnderRight)

    return sumUnderRight + sumUnderLeft + root.val
