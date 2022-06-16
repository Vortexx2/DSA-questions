"""
  @author Vortexx2
  Problem 99 - Recover BST

  @approach Inorder traversal of a BST should be in ascending order. Figure out
  which two nodes should be swapped to obtain ascending order.

  Runtime - 107 ms
  Memory Usage - 14.3 MB
"""
from typing import Optional, List, Tuple


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def recoverTree(self, root: Optional[TreeNode]) -> None:
    """
    Do not return anything, modify root in-place instead.
    """

    self.values = []
    self.inorderTraversal(root)

    self.first, self.second = self.findSwappedElems()

    self.findAndUpdate(root)

  def inorderTraversal(self, root: Optional[TreeNode]) -> None:

    if not root:
      return

    self.inorderTraversal(root.left)
    self.values.append(root.val)
    self.inorderTraversal(root.right)

  def findSwappedElems(self) -> Tuple[int, int]:

    first, second = None, None

    prev = self.values[0]
    for i in range(1, len(self.values)):
      if prev > self.values[i]:
        first = prev
        break

      prev = self.values[i]

    prev = self.values[-1]
    for i in range(len(self.values) - 2, -1, -1):
      if prev < self.values[i]:
        second = prev
        break

      prev = self.values[i]

    return first, second

  def findAndUpdate(self, root: Optional[TreeNode]) -> None:

    if not root:
      return

    self.findAndUpdate(root.left)

    if root.val == self.first:
      root.val = self.second
    elif root.val == self.second:
      root.val = self.first

    self.findAndUpdate(root.right)
