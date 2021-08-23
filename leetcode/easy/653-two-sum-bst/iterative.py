"""
  @author Vortexx2
  Problem 653 - Two Sum IV

  Runtime - 80 ms
  Memory Usage - 16.4 MB
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def findTarget(self, root: Optional[TreeNode], k: int) -> bool:

    def pushLeft(st: List[TreeNode], root: TreeNode):
      while root:
        st.append(root)
        root = root.left

    def pushRight(st: List[TreeNode], root: TreeNode):
      while root:
        st.append(root)
        root = root.right

    def nextLeft(st: List[TreeNode]) -> int:
      node = st.pop()
      pushLeft(st, root.right)
      return node.val

    def nextRight(st: List[TreeNode])-> int:
      node = st.pop()
      pushRight(st, root.left)
      return node.val

    lSt, rSt = [], []
    pushLeft(lSt, root)
    pushRight(rSt, root)
    left, right = nextLeft(lSt), nextRight(rSt)

    while left < right:
      if left + right == k: return True
      if left + right < k:
        left = nextLeft(lSt)
      else:
        right = nextRight(rSt)

    return False
