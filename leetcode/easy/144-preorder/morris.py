"""
  @author Vortexx2
  Problem 144 - Binary Tree Preorder Traversal

  Runtime - 24 ms
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
  def preorderTraversal(self, root: TreeNode) -> List[int]:
    res = []

    while root:
      if (root.left):
        predec = self.find_predecessor(root)

        if (predec.right):
          predec.right = None
          root = root.right

        else:
          predec.right = root
          res.append(root.val)
          root = root.left

      else:
        res.append(root.val)
        root = root.right

    return res

  def find_predecessor(self, node: TreeNode) -> TreeNode:
    curr = node.left

    while curr.right and (curr.right != node):
      curr = curr.right

    return curr
