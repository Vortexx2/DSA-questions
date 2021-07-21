"""
  @author Vortexx2
  Problem 589 - N-ary Preorder Traversal

  Runtime - 52 ms
  Memory Usage - 15.9 MB
"""
from typing import List


# Definition for a Node.
class Node:
  def __init__(self, val=None, children=None):
    self.val = val
    self.children = children


class Solution:
  def preorder(self, root: 'Node') -> List[int]:
    res = []
    self.helper(root, res)

    return res

  def helper(self, root: 'Node', arr: List[int]) -> None:

    if root:
      arr.append(root.val)

      for child in root.children:
        self.helper(child, arr)
