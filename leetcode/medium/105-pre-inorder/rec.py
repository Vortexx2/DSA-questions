"""
  @author Vortexx2
  Problem 105
  Adding a map brought down runtime from 548 ms to 48 ms

  Runtime - 48 ms
  Memory Usage - 18 MB
"""
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    if not preorder:
      return None

    self.index = 0
    self.map = {}
    for index, val in enumerate(inorder):
      self.map[val] = index
    return self.helper(preorder, inorder, 0, len(preorder))

  def helper(self, preorder, inorder, start, end) -> Optional[TreeNode]:
    respectiveIndex = self.index
    if end - start == 1:
      return TreeNode(preorder[self.index])

    i = self.map[preorder[self.index]]

    left, right = None, None
    if i - start > 0:
      # left subtree exists for this node
      self.index += 1
      left = self.helper(preorder, inorder, start, i)

    if end - i > 1:
      # right subtree exists for this node
      self.index += 1
      right = self.helper(preorder, inorder, i + 1, end)

    newNode = TreeNode(preorder[respectiveIndex], left, right)
    return newNode
