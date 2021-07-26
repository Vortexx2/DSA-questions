"""
  @author Vortexx2
  Problem 701 - Insert into BST

  Runtime - 132 ms
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

    curr, prev = root, None

    while curr:
      prev = curr
      if curr.val < val:
        curr = curr.right

      else:
        curr = curr.left

    if prev.val < val:
      prev.right = newNode

    else:
      prev.left = newNode

    return root
