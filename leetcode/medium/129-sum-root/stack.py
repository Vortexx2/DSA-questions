"""
  @author Vortexx2
  Problem 129 - Sum Root to Leaf
  @approach Iterative Preorder approach

  Runtime - 32 ms
  Memory Usage - 14.2 MB
"""
# Definition for a binary tree node.


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sumNumbers(self, root: TreeNode) -> int:
    st = [(root, root.val)]
    res = 0

    while st:
      top, running = st.pop()

      if not top.left and not top.right:
        res += running

      else:
        if top.left:
          st.append((top.left, running * 10 + top.left.val))

        if top.right:
          st.append((top.right, running * 10 + top.right.val))

    return res
