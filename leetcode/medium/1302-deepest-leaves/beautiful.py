"""
  @author Vortexx2
  Problem 1302

  Runtime - 88 ms
  Memory Usage - 17.6 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def deepestLeavesSum(self, root: TreeNode) -> int:
    if not root:
      return 0
    currSum = 0

    level = [root]

    while level:
      currSum = 0
      nextLevel = []

      for node in level:
        currSum += node.val
        if node.left: nextLevel.append(node.left)
        if node.right: nextLevel.append(node.right)

      level = nextLevel

    return currSum

