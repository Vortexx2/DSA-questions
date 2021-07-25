"""
  @author Vortexx2
  Problem 700 - Search in a BST

  Runtime - 76 ms
  Memory Usage - 16 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def searchBST(self, root: TreeNode, val: int) -> TreeNode:

    if root.val == val:
      return root

    while (root is not None):

      if root.val == val:
        return root

      if (root.val < val):
        root = root.right

      else:
        root = root.left

    return None
