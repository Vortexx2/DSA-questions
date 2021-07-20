"""
  @author Vortexx2

  Runtime - 24 ms
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
    st = []
    ans = []

    while True:

      while root:
        ans.append(root.val)
        st.append(root)
        root = root.left

      if not len(st):
        break

      root = st.pop().right

    return ans

