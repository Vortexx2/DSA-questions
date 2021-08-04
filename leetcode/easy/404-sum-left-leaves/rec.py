"""
  @author Vortexx2
  Problem 404 - Sum Left Leaves
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sumOfLeftLeaves(self, root: TreeNode, left=False) -> int:
    if left and not root.left and not root.right:
      return root.val

    a = 0
    if (root.left):
      a += self.sumOfLeftLeaves(root.left, True)
    if (root.right):
      a += self.sumOfLeftLeaves(root.right, False)

    return a
