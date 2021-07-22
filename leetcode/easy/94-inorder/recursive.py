"""
  @author Vortexx2
  Problem 94 - Binary Tree Inorder Traversal
  
  Runtime - 32 ms
  Memory Usage - 14.3 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def inorderTraversal(self, root: TreeNode) -> List[int]:
    res = []
    self.helper(root, res)
    return res

  def helper(self, root: TreeNode, arr: List[int]) -> None:
    if root:
      self.helper(root.left, arr)
      arr.append(root.val)
      self.helper(root.right, arr)
