"""
  @author Vortexx2
  Problem 700 - Search in a BST

  Runtime - 64 ms
  Memory Usage - 16.2 MB
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

    return self.helper(root, val)


  def helper(self, curr: TreeNode, val: int) -> TreeNode:

    if not curr:
      return None

    if curr.val == val:
      return curr

    if curr.val < val:
      res = self.helper(curr.right)

    else:
      res = self.helper(curr.left)

    return res
