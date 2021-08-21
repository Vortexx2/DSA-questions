"""
  @author Vortexx2
  Problem 637

  Runtime - 48 ms
  Memory Usage - 17.5 MB
"""
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
    res, hel = [], []

    def helper(node: TreeNode, level: int) -> None:
      if not node:
        return

      if level >= len(hel):
        hel.append((node.val, 1))

      else:
        hel[level] = (hel[level][0] + node.val, hel[level][1] + 1)

      helper(node.left, level + 1)
      helper(node.right, level + 1)

    helper(root, 0)

    for i in range(len(hel)):
      res.append(hel[i][0] / hel[i][1])

    return res
