"""
  @author Vortexx2
  Problem 1161 - Maximum Level Sum

  Runtime - 326 ms
  Memory Usage - 18.3 MB
"""
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def maxLevelSum(self, root: Optional[TreeNode]) -> int:
    levelSum = []

    self.helper(root, 0, levelSum)
    maxSum, maxLevel = -1e5, 1
    for i in range(len(levelSum)):
      if levelSum[i] > maxSum:
        maxSum = levelSum[i]
        maxLevel = i + 1

    return maxLevel

  def helper(self, root: TreeNode, level: int, levelSum: List[int]) -> None:

    if not root:
      return

    if level >= len(levelSum):
      levelSum.append(root.val)

    else:
      levelSum[level] += root.val

    self.helper(root.left, level + 1, levelSum)
    self.helper(root.right, level + 1, levelSum)
