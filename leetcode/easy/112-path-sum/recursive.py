"""
  @author Vortexx2
  Problem 112 - Path Sum

  Runtime - 36 ms
  Memory Usage - 15.8 MB
"""
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:

    if not root:
      return False

    if (not root.left and not root.right and targetSum == root.val):
      return True

    a = targetSum - root.val
    return self.hasPathSum(root.left, a) or self.hasPathSum(root.right, a)
