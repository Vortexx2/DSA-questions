"""
  @author Vortexx2
  Problem 543 - Diameter BT

  Runtime - 620 ms
  Memory Usage - 15.9 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def diameterOfBinaryTree(self, root: TreeNode) -> int:
    if not root:
      return 0

    lheight, rheight = self.height(root.left), self.height(root.right)

    return max(lheight + rheight, max(self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right)))

  def height(self, root: TreeNode) -> int:
    if not root:
      return 0

    return max(self.height(root.left), self.height(root.right)) + 1
