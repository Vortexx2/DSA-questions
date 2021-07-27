"""
  @author Vortexx2 
  Problem 919 - CBT Inserter

  Runtime - 56 ms
  Memory Usage - 14.9 MB
"""
from collections import deque


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class CBTInserter:

  def __init__(self, root: TreeNode):
    self.dq = deque([])
    self.root = root
    q = deque([root])

    while q:
      node = q.popleft()

      if not node.left or not node.right:
        self.dq.append(node)

      if node.left:
        q.append(node.left)

      if node.right:
        q.append(node.right)

  def insert(self, v: int) -> int:
    node = self.dq[0]
    new_node = TreeNode(v)
    self.dq.append(new_node)

    if not node.left:
      node.left = new_node

    else:
      node.right = new_node
      self.dq.popleft()

    return node.val

  def get_root(self) -> TreeNode:
    return self.root
