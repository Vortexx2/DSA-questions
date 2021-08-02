"""
  @author Vortexx2
  Problem 104 - Max Depth Of BT

  Runtime - 32 ms
  Memory Usage - 16.7 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def maxDepth(self, root: TreeNode, level=1) -> int:
    if not root:
      return level - 1

    a = self.maxDepth(root.left, level + 1)
    b = self.maxDepth(root.right, level + 1)
    return max(a, b)
