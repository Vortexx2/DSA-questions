"""
  @author Vortexx2
  Problem 257 - BT Paths

  Runtime - 28 ms
  Memory Usage - 14.2 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def binaryTreePaths(self, root: TreeNode) -> List[str]:
    if not root:
      return []

    arr, path = [], str(root.val)
    self.helper(root, arr, path)
    return arr

  def helper(self, node: TreeNode, arr: List[str], path: str) -> None:

    if not node.left and not node.right:
      arr.append(path)
      return

    if node.left:
      self.helper(node.left, arr, path + "->" + str(node.left.val))
    if node.right:
      self.helper(node.right, arr, path + "->" + str(node.right.val))
