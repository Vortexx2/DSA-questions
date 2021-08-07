"""
  @author Vortexx2
  Problem 429

  Runtime - 44 ms
  Memory Usage - 15.8 MB
"""
from typing import List


class Node:
  def __init__(self, val=None, children=None):
    self.val = val
    self.children = children


class Solution:
  def levelOrder(self, root: 'Node') -> List[List[int]]:

    res = []
    if not root:
      return res

    level = [root]

    while root and level:
      currNodes, nextLevel = [], []

      for node in level:
        currNodes.append(node.val)

        for child in node.children:
          nextLevel.append(child)

      res.append(currNodes)
      level = nextLevel

    return res
