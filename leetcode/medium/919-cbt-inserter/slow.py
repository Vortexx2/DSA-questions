"""
  @author Vortexx2
  Problem 919 - Complete Binary Tree Inserter

  Runtime - 448 ms
  Memory Usage - 15.2 MB
"""
from collections import deque


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class CBTInserter:

  def __init__(self, root: TreeNode):
    self.root = root

  def insert(self, v: int) -> int:
    new_node = TreeNode(v)

    if not self.root:
      self.root = new_node
      return v

    q = deque([self.root])

    while q:
      front = q.pop()
      if not front.left:
        front.left = new_node
        return front.val

      if not front.right:
        front.right = new_node
        return front.val

      q.appendleft(front.left)
      q.appendleft(front.right)

  def get_root(self) -> TreeNode:
    return self.root
