"""
  @author Vortexx2
  Problem 95 - Unique BST 2

  Runtime - 78 ms
  Memory Usage - 17 MB
"""
from typing import *


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def clone(self, root: TreeNode) -> TreeNode:
    if not root:
      return None

    return TreeNode(root.val, self.clone(root.left), self.clone(root.right))

  def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
    res = [None]

    for i in range(1, n + 1):
      temp = []
      for j in range(len(res)):
        oldRoot = res[j]
        root = TreeNode(i)
        root.left = self.clone(oldRoot)
        temp.append(root)

        if oldRoot is not None:
          tempOld = oldRoot

          while tempOld:
            tright = tempOld.right
            newRoot = TreeNode(i)
            tempOld.right = newRoot
            newRoot.left = tright
            temp.append(self.clone(oldRoot))
            tempOld.right = tright
            tempOld = tempOld.right

      res = temp

    return res
