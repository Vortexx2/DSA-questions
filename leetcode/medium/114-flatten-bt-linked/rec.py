"""
  @author Vortexx2
  Problem 114 - Flatten BT To Linked List

  Runtime - 32 ms O(n)
  Memory Usage - 15.3 MB O(h)
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    """
    Do not return anything, modify root in-place instead.
    """
    if not root:
      return

    self.helper(root)

  def helper(self, root: TreeNode) -> TreeNode:
    if not root:
      return None

    left, right = self.helper(root.left), self.helper(root.right)
    temp = root.right

    if root.left:
      root.right = root.left
      left.right = temp

    root.left = None

    if right:
      return right
    if left:
      return left
    return root
