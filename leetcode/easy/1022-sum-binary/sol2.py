"""
  @author Vortexx2
  Problem 1022

  Runtime - 43 ms
  Memory Usage - 14.3 MB
"""
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:

    self.ans = 0
    self.writePaths(root, 0)

    return self.ans

  def writePaths(self, root: TreeNode, running: int) -> None:

    if not root:
      return

    running = running << 1 | root.val

    if not root.left and not root.right:
      self.ans += running

    else:
      self.writePaths(root.left, running)
      self.writePaths(root.right, running)
