"""
  @author Vortexx2

  Runtime - 32 ms
  Memory Usage - 14.3 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def preorderTraversal(self, root: TreeNode) -> List[int]:
    res = []
    self.helper(root, res)

    return res

  def helper(self, root: TreeNode, res: List[int]):

    if root:
      res.append(root.val)
      self.helper(root.left, res)
      self.helper(root.right, res)