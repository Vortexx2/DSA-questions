"""
  @author Vortexx2
  Problem 226 - Invert BT

  Runtime - 24 ms
  Memory Usage - 14.4 MB
"""
# Definition for a binary tree node.


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def invertTree(self, root: TreeNode) -> TreeNode:
    if not root:
      return None

    right = self.invertTree(root.right)
    root.right = self.invertTree(root.left)
    root.left = right
    return root
