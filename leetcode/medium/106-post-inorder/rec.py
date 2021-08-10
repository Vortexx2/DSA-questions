"""
  @author Vortexx2
  Problem 106 - Construct BT From Inorder and Postorder Traversal

  Runtime - 60 ms
  Memory Usage - 17.8 MB
"""
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
    if not inorder:
      return None

    self.index = -1
    self.dic = {}

    for i, val in enumerate(inorder):
      self.dic[val] = i

    return self.helper(inorder, postorder, 0, len(inorder))

  def helper(self, inorder, postorder, start: int, end: int) -> Optional[TreeNode]:

    if end - start == 1:
      return TreeNode(postorder[self.index])

    respectiveIndex = self.index
    i = self.dic[postorder[self.index]]

    left, right = None, None
    if end - i > 1:
      # right subtree exists
      self.index -= 1
      right = self.helper(inorder, postorder, i + 1, end)

    if i - start > 0:
      # left subtree exists
      self.index -= 1
      left = self.helper(inorder, postorder, start, i)

    return TreeNode(postorder[respectiveIndex], left, right)
