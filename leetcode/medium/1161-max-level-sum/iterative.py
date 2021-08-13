"""
  @author Vortexx2
  Problem 1161 - Maximum Level Sum

  Runtime - 409 ms
  Memory Usage - 18.8 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def maxLevelSum(self, root: Optional[TreeNode]) -> int:
    level = [root]
    maxSum, maxLevel = -1e5, 1
    i = 1

    while level:
      currSum = 0
      nextLevel = []

      for node in level:
        currSum += node.val

        if node.left:
          nextLevel.append(node.left)
        if node.right:
          nextLevel.append(node.right)

      if currSum > maxSum:
        maxSum = currSum
        maxLevel = i

      level = nextLevel
      i += 1

    return maxLevel
