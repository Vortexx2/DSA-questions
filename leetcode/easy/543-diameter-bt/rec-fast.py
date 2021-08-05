"""
  @author Vortexx2
  Problem 543 - Diameter BT

  Runtime - 40 ms
  Memory Usage - 15.8 MB
"""
# Definition for a binary tree node.


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def diameterOfBinaryTree(self, root: TreeNode) -> int:
    if not root:
      return 0

    self.res = 0
    self.helper(root)
    return self.res

  def helper(self, node: TreeNode):
    if not node:
      return 0

    lh = self.helper(node.left)
    rh = self.helper(node.right)
    self.res = max(self.res, lh + rh)
    return 1 + max(lh, rh)
