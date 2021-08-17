"""
  @author Vortexx2
  Problem 129 - Sum Root to Leaf

  Runtime - 32 ms
  Memory Usage - 14.2 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sumNumbers(self, root: TreeNode) -> int:
    self.ans = 0

    self.helper(root, 0)
    return self.ans

  def helper(self, root: TreeNode, running: int) -> None:
    running = running * 10 + root.val

    if not root.left and not root.right:
      self.ans += running

    if root.left:
      self.helper(root.left, running)

    if root.right:
      self.helper(root.right, running)