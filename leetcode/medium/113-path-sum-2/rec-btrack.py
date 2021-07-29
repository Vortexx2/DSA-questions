"""
  @author Vortexx2
  Problem 113 - Path Sum II

  Runtime - 44 ms
  Memory Usage - 15.3 MB
"""
from typing import List


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:

    res, path = [], []
    self.helper(root, targetSum, path, res)
    return res

  def helper(self, curr: TreeNode, sm: int, path: List[int], res: List[List[int]]) -> None:

    if not curr:
      return

    path.append(curr.val)

    if not curr.left and not curr.right and curr.val == sm:
      res.append(path.copy())

    self.helper(curr.left, sm - curr.val, path, res)
    self.helper(curr.right, sm - curr.val, path, res)

    path.pop()
