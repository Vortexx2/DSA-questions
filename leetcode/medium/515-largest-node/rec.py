"""
  @author Vortexx2
  Problem 515 - Largest Value in Tree Row
  
  Runtime - 62 ms
  Memory Usage - 17.1 MB
"""
from math import inf
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:

  def largestValues(self, root: Optional[TreeNode]) -> List[int]:
    self.res = []
    if not root:
      return []

    self.helper(root, 0)
    return self.res

  def helper(self, root: Optional[TreeNode], level: int) -> None:
    if not root:
      return

    if len(self.res) <= level:
      self.res.append(root.val)

    else:
      self.res[level] = max(self.res[level], root.val)

    self.helper(root.left, level + 1)
    self.helper(root.right, level + 1)
