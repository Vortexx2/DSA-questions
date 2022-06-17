"""
  @author Vortexx2
  Problem 1382 - Balance a BST

  Runtime - 851 ms
  Memory Usage - 20.5 MB
"""
from typing import Optional
from math import floor


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def balanceBST(self, root: TreeNode) -> TreeNode:
    if not root:
      return None

    self.inorder = []
    self.inorderTraversal(root)

    return self.constructBalancedBST(0, len(self.inorder))

  def inorderTraversal(self, root: Optional[TreeNode]) -> None:

    if not root:
      return

    self.inorderTraversal(root.left)
    self.inorder.append(root.val)
    self.inorderTraversal(root.right)

  def constructBalancedBST(self, start: int, end: int) -> Optional[TreeNode]:

    if start == end:
      return None

    mid = floor((start + end) / 2)

    root = TreeNode(self.inorder[mid])
    root.left = self.constructBalancedBST(start, mid)
    root.right = self.constructBalancedBST(mid + 1, end)

    return root
