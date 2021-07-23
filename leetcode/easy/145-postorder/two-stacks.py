"""
  @author Vortexx2
  Problem 145 - Binary Tree Postorder Traversal

  Runtime - 32 ms
  Memory Usage - 14.4 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def postorderTraversal(self, root: TreeNode) -> List[int]:
    if not root:
      return []

    st1, st2 = [root], []

    while st1:
      root = st1.pop()
      st2.append(root)

      if root.left:
        st1.append(root.left)

      if root.right:
        st1.append(root.right)

    res = []
    while st2:
      res.append(st2.pop().val)

    return res
