"""
  @author Vortexx2
  Problem 98 - Validate BST

  Runtime - 44 ms
  Memory Usage - 16.4 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isValidBST(self, root: Optional[TreeNode], mn: int = float('-inf'), mx: int = float('inf')) -> bool:
    if not root:
      return True

    return (root.val > mn and root.val < mx and self.isValidBST(root.left, mn, root.val) and self.isValidBST(root.right, root.val, mx))
