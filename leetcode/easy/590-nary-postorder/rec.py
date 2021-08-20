"""
  @author Vortexx2
  Problem 590 - Nary Postorder

  Runtime - 48 ms
  Memory Usage - 16 MB
"""
from typing import List


class Node:
  def __init__(self, val=None, children=None):
    self.val = val
    self.children = children


class Solution:
  def postorder(self, root: 'Node') -> List[int]:
    if not root:
      return []

    res = []

    def helper(node: Node) -> None:
      if not node:
        return

      for child in node.children:
        helper(child)

      res.append(node.val)

    helper(root)
    return res
