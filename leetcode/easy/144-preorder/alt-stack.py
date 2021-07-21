"""
  @author Vortexx2

  Runtime - 28 ms
  Memory Usage - 14.2 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def preorderTraversal(self, root: TreeNode) -> List[int]:
    st, res = [root], []

    while st:
      node = st.pop()

      if node:
        res.append(node.val)
        st.append(node.right)
        st.append(node.left)

    return res
