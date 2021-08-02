"""
  @author Vortexx2
  Problem 111 - Minimum Depth of BT

  Runtime - 612 ms
  Memory Usage - 53 MB
"""


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def minDepth(self, root: TreeNode) -> int:
    if not root:
      return 0

    if not root.left and not root.right:
      return 1

    a, b = 1e5, 1e5

    if root.left:
      a = self.minDepth(root.left)

    if root.right:
      b = self.minDepth(root.right)

    return min(a, b) + 1
