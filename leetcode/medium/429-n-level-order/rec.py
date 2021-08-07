"""
  @author Vortexx2
  Problem 429 - N-ary Tree Level Order Traversal

  Runtime - 48 ms
  Memory Usage - 16 MB
"""
from typing import List


class Node:
  def __init__(self, val=None, children=None):
    self.val = val
    self.children = children


class Solution:
  def levelOrder(self, root: 'Node') -> List[List[int]]:
    if not root:
      return []

    res = []
    self.helper(root, res, 0)
    return res

  def helper(self, node: Node, res: List[List[int]], level: int) -> None:

    if level >= len(res):
      res.append([node.val])

    else:
      res[level].append(node.val)

    for child in node.children:
      self.helper(child, res, level + 1)
