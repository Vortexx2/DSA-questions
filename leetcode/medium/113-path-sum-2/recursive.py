"""
  @author Vortexx2
  Problem 113 - Path Sum II

  Runtime - 40 ms
  Memory Usage - 15.4 MB
"""
from typing import Deque, List
from collections import deque


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:

    res = self.helper(root, targetSum)
    for subarr in res:
      subarr.reverse()

    return res

  def helper(self, curr: TreeNode, targetSum: int) -> List[List[int]]:

    if not curr:
      return []

    if not curr.left and not curr.right and curr.val == targetSum:
      return [[curr.val]]

    a = self.helper(curr.left, targetSum - curr.val)
    for l in a:
      if l:
        l.append(curr.val)

    b = self.helper(curr.right, targetSum - curr.val)
    for l in b:
      if l:
        l.append(curr.val)

    for c in b:
      if c:
        a.append(c)

    return a
