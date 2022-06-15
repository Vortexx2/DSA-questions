"""
  @author Vortexx2
  Problem 515 - Largest Value in Tree Row
  
  Runtime - 63 ms
  Memory Usage - 16.3 MB
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

    if not root:
      return []

    res = [root.val]
    level = [root]

    while level:
      currMax = -inf
      nextLevel = []

      for node in level:
        if node.left:
          currMax = max(currMax, node.left.val)
          nextLevel.append(node.left)

        if node.right:
          currMax = max(currMax, node.right.val)
          nextLevel.append(node.right)

      level = nextLevel
      if nextLevel:
        res.append(currMax)

    return res
