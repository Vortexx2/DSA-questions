"""
  @author Vortexx2
  Problem 653 - Two Sum IV - Input is a BST

  Runtime - 72 ms
  Memory Usage - 18 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
    self.dic = {}

    def helper(root: TreeNode) -> bool:
      if not root:
        return False

      if (k - root.val) in self.dic:
        return True

      self.dic[root.val] = True
      return helper(root.left) or helper(root.right)

    return helper(root)
