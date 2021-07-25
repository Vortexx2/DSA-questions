"""
  @author Vortexx2
  Problem 102 - Binary Tree Level Order Traversal

  Runtime - 24 ms
  Memory Usage - 14.2 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
    res = []

    if not root:
      return res

    level = [root]
    while root and level:
      currNodes = []
      nextLevel = []

      for node in level:
        currNodes.append(node.val)
        if node.left:
          nextLevel.append(node.left)

        if node.right:
          nextLevel.append(node.right)

      res.append(currNodes)
      level = nextLevel

    return list(reversed(res))
