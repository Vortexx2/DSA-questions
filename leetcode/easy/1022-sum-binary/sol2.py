"""
  @author Vortexx2
  Problem 1022

  Runtime - 36 ms
  Memory Usage - 14.7 MB
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
    path = []

    self.ans = 0
    self.writePaths(root, path)

    return self. ans

  def binaryToInt(self, arr: List[int]) -> int:
    res = 0
    for el in arr:
      res = res << 1 | el

    return res

  def writePaths(self, root: TreeNode, path: List[int]) -> None:

    if not root:
      return

    path.append(root.val)
    if not root.left and not root.right:
      self.ans += self.binaryToInt(path)

    else:
      self.writePaths(root.left, path)
      self.writePaths(root.right, path)

    path.pop()
