"""
  @author Vortexx2
  Problem 145 - Binary Tree Postorder Traversal

  Runtime - 32 ms
  Memory Usage - 14.1 MB
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

    st = []
    res = []

    while True:

      while root:
        st.append(root)
        root = root.left

      if not st:
        return res

      root = st[-1]
      prev = None
      while ((not root.right) or (root.right == prev)):
        res.append(root.val)
        st.pop()

        if not st:
          return res

        prev = root
        root = st[-1]

      root = root.right
