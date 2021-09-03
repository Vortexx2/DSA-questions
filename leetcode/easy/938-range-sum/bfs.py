"""
  @author Vortexx2
  Problem 938 - Range Sum of BST
  
  Runtime - 192 ms
  Memory Usage - 22.5 MB
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
    if not root:
      return 0

    currLevel = [root]
    total = 0

    while currLevel:
      nextLevel = []

      for node in currLevel:
        if node.val < low:
          if node.right:
            nextLevel.append(node.right)
          
        elif node.val > high:
          if node.left:
            nextLevel.append(node.left)

        else:
          total += node.val
          if node.left: nextLevel.append(node.left)
          if node.right: nextLevel.append(node.right)

      currLevel = nextLevel

    return total
