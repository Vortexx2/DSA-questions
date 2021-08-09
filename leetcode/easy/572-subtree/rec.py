"""
  @author Vortexx2
  Problem 572 - Subtree of Another Tree

  Runtime - 164 ms
  Memory Usage - 15.1 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
    return self.checkSubtree(root, subRoot, subRoot)

  def checkSubtree(self, root: TreeNode, subRoot: TreeNode, subRootOrigin: TreeNode) -> bool:

    if not root and not subRoot:
      return True

    if not root or not subRoot:
      return False

    if root.val == subRoot.val:
      if self.checkSubtree(root.left, subRoot.left, subRootOrigin) and self.checkSubtree(root.right, subRoot.right, subRootOrigin):
        return True

    if subRoot == subRootOrigin:
      return self.checkSubtree(root.left, subRootOrigin, subRootOrigin) or self.checkSubtree(root.right, subRootOrigin, subRootOrigin)

    return False
