"""
  @author Vortexx2
  Problem 100

  Runtime - 28 ms
  Memory Usage - 14.1 MB
"""
from collections import deque


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
    st = [(p, q)]

    while st:
      node1, node2 = st.pop()

      if node1 and node2:
        if node1.val != node2.val:
          return False

        st.append((node1.right, node2.right))
        st.append((node1.left, node2.left))

      else:
        if node1 or node2:
          return False

    return True
