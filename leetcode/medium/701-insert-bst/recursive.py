"""
  @author Vortexx2
  Problem 701 - Insert into BST

  Runtime - 136 ms
  Memory Usage - 16.9 MB
"""
# Definition for a binary tree node.


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
    newNode = TreeNode(val)
    if not root:
      root = newNode
      return root

    def dfs(root: TreeNode, val: int):

      if root.val < val:
        if root.right:
          dfs(root.right, val)

        else:
          root.right = TreeNode(val)

      else:

        if root.left:
          dfs(root.left, val)

        else:
          root.left = TreeNode(val)

    dfs(root, val)
    return root
