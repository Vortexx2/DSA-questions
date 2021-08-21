"""
  @author Vortexx2
  Problem 637

  Runtime - 40 ms
  Memory Usage - 16.6 MB
"""
from typing import List, Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
    res = []
    level = [root]

    while level:
      nextLevel, currLevel = [], []
      currSum = 0

      for node in level:
        currSum += node.val
        if node.left:
          nextLevel.append(node.left)

        if node.right:
          nextLevel.append(node.right)

      res.append(currSum / len(level))
      level = nextLevel

    return res
