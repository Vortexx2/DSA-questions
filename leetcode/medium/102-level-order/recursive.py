"""
  @author Vortexx2
  Problem 102 - Binary Tree Level Order Traversal

  Runtime - 36 ms
  Memory Usage - 15.1 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def levelOrder(self, root: TreeNode) -> List[List[int]]:
    res = []

    if not root:
      return res

    self.traverse(root, res, 0)
    return res

  def traverse(self, curr: TreeNode, arr: List[List[int]], level: int) -> None:

    if not curr:
      return

    if level >= len(arr):
      arr.append([curr.val])

    else:
      arr[level].append(curr.val)

    self.traverse(curr.left, arr, level + 1)
    self.traverse(curr.right, arr, level + 1)
