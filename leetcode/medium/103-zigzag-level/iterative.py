"""
  @author Vortexx2
  Problem 103 - Zigzag level Order Traversal

  Runtime - 20 ms
  Memory Usage - 14.4 MB
"""
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
      return []

    level = [root]
    res = []

    i = 0

    while level:
      currNodes, nextLevel = [], []

      for node in level:
        currNodes.append(node.val)

        if node.left:
          nextLevel.append(node.left)

        if node.right:
          nextLevel.append(node.right)

      if (i % 2 == 1):
        currNodes.reverse()

      res.append(currNodes)
      level = nextLevel
      i += 1

    return res
