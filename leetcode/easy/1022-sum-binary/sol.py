"""
  @author Vortexx2
  Problem 1022

  Runtime - 55 ms
  Memory Usage - 14.4 MB
"""
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
    path, allPaths = [], []

    self.writePaths(root, path, allPaths)
    res = 0
    for arr in allPaths:
      res += self.binaryToInt(arr)

    return res

  def binaryToInt(self, arr: List[int]) -> int:
    res = 0
    for el in arr:
      res = res << 1 | el

    return res

  def writePaths(self, root: TreeNode, path: List[int], allPaths: List[List[int]]) -> None:

    if not root:
      return

    path.append(root.val)
    if not root.left and not root.right:
      allPaths.append(path.copy())

    else:
      self.writePaths(root.left, path, allPaths)
      self.writePaths(root.right, path, allPaths)

    path.pop()
