"""
  @Author Vortexx2
  Probelm 110 - Balanced Binary Tree

  Runtime - 44 ms
  Memory Usage - 18 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isBalanced(self, root: TreeNode) -> bool:
    if not root:
      return True

    return False if self.helper(root) == -1 else True

  def helper(self, node: TreeNode) -> int:

    if not node:
      return 0

    a = self.helper(node.left)
    if a == -1:
      return -1

    b = self.helper(node.right)
    if b == -1:
      return -1

    if (abs(b - a) > 1):
      return -1

    return max(a, b) + 1
