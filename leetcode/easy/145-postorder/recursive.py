"""
  @author Vortexx2
  Problem 145 - Binary Tree Postorder Traversal

  Runtime - 32 ms
  Memory Usage - 14 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def postorderTraversal(self, root: TreeNode) -> List[int]:
    res = []
    self.helper(root, res)
    return res

  def helper(self, node: TreeNode, arr: List[int]) -> None:
    if node:
      self.helper(node.left, arr)
      self.helper(node.right, arr)
      arr.append(node.val)