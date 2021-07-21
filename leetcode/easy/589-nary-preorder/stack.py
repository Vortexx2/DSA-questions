"""
  @author Vortexx2
  Problem 589 - N-ary Preorder Traversal

  Runtime - 52 ms
  Memory Usage - 16.2 MB
"""
from typing import List


# Definition for a Node.
class Node:
  def __init__(self, val=None, children=None):
    self.val = val
    self.children = children


class Solution:
  def preorder(self, root: 'Node') -> List[int]:
    
    if not root:
      return []

    res = []
    st = [root]

    while len(st):
      top = st.pop()
      res.append(top.val)

      for child in reversed(top.children):
        st.append(child)
    
    return res

