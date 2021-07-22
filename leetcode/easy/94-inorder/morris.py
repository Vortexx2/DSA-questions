"""
  @author Vortexx2
  Problem 94 - Binary Tree Inorder Traversal
  
  Runtime - 32 ms
  Memory Usage - 14.4 MB
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

    while root:

      if root.left:
        predec = self.findPredecessor(root)

        if predec.right:
          predec.right = None
          res.append(root.val)
          root = root.right

        else:
          predec.right = root
          root = root.left

      else:
        res.append(root.val)
        root = root.right

    return res

  def findPredecessor(self, node: TreeNode) -> TreeNode:
    curr = node.left
    while (curr.right and curr.right != node):
      curr = curr.right

    return curr
