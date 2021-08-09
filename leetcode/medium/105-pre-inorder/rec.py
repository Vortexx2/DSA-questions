"""
  @author Vortexx2
  Problem 105

  Runtime - 548 ms
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
    return self.helper(preorder, inorder, 0, len(preorder))

  def helper(self, preorder, inorder, start, end) -> Optional[TreeNode]:

    respectiveIndex = self.index
    if end - start == 1:
      return TreeNode(preorder[self.index])

    i = start
    while i < end:
      if inorder[i] == preorder[self.index]:
        break
      i += 1

    left, right = None, None
    if i - start > 0:
      # left subtree exists for this node
      self.index += 1
      left = self.helper(preorder, inorder, start, i)

    if end - i > 1:
      self.index += 1
      right = self.helper(preorder, inorder, i + 1, end)

    newNode = TreeNode(preorder[respectiveIndex], left, right)
    return newNode

