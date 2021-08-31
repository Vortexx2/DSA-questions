"""
  @author Vortexx2
  Problem 95 - Unique BST 2
  @approach This approach uses a dictionary as a DP approach to be able to reduce the memory used in the recursive stack.

  Runtime - 102 ms
  Memory Usage - 14.9 MB
"""
from typing import *


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
    cache = {}

    def helper(start: int, end: int) -> List[Optional[TreeNode]]:
      if start > end:
        return [None]

      if (start, end) in cache: return cache[(start, end)]

      res = []
      for i in range(start, end + 1):
        left = helper(start, i - 1)
        right = helper(i + 1, end)

        for leftNode in left:
          for rightNode in right:
            root = TreeNode(i, leftNode, rightNode)
            res.append(root)

      cache[(start, end)] = res
      return res

    return helper(1, n)
