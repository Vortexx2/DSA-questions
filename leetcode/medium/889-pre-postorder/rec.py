"""
  @author Vortexx2
  Problem 889 - Construct BT From Preorder & Postorder

  Runtime - 40 ms O(n)
  Memory Usage - 14.2 MB O(h)
"""
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
    self.preIndex, self.postIndex = 0, 0

    def helper() -> TreeNode:
      root = TreeNode(preorder[self.preIndex])
      self.preIndex += 1

      if root.val != postorder[self.postIndex]:
        root.left = helper()

      if root.val != postorder[self.postIndex]:
        root.right = helper()

      self.postIndex += 1
      return root

    return helper()
