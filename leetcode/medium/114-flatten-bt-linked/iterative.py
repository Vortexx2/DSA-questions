"""
  @author Vortexx2

  Runtime - 36 ms O(n)
  Memory Usage - 15.2 MB O(1)
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

    while root:
      if root.left:
        pre = root.left
        while pre.right:
          pre = pre.right

        pre.right = root.right
        root.right = root.left
        root.left = None

      root = root.right
