"""
  @author Vortexx2
  Problem 94 - Binary Tree Inorder Traversal
  
  Runtime - 32 ms
  Memory Usage - 14.3 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def inorderTraversal(self, root: TreeNode) -> List[int]:
    res = []
    st = []

    while True:

      while root:
        st.append(root)
        root = root.left

      if not st:
        break

      root = st.pop()
      res.append(root.val)
      root = root.right

    return res
