"""
  @author Vortexx2
  Problem 101 - Symmetric Tree

  Runtime - 28 ms
  Memory Usage - 14.4 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSymmetric(self, root: TreeNode) -> bool:
    if not root:
      return True

    st = [(root.left, root.right)]

    while st:
      first, second = st.pop()

      if first and second:
        if first.val != second.val:
          return False
        st.append((first.left, second.right))
        st.append((first.right, second.left))

      else:
        if first or second:
          return False

    return True
