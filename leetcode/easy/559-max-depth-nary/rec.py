"""
  @author Vortexx2
  Problem 559 - Max Depth N-ary

  Runtime - 32 ms
  Memory Usage - 16 MB
"""


class Node:
  def __init__(self, val=None, children=None):
    self.val = val
    self.children = children


class Solution:
  def maxDepth(self, root: 'Node') -> int:
    if not root:
      return 0
    
    maxLevel = 0
    for node in root.children:
      maxLevel = max(maxLevel, self.maxDepth(node))
    
    return maxLevel + 1
