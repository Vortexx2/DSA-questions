"""
  @author Vortexx2
  Problem 113 - Path Sum II

  Runtime - 40 ms
  Memory Usage - 14.9 MB
"""
from typing import Deque, List
from collections import deque


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
    if not root:
      return []
    st = [(root, [root.val])]
    res = []

    while st:

      root, l = st.pop()
      if not root.right and not root.left and sum(l) == targetSum:
        res.append(l)

      if root.right:
        st.append((root.right, l + [root.right.val]))

      if root.left:
        st.append((root.left, l + [root.left.val]))

    return res
