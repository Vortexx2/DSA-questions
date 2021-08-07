"""
  @author Vortexx2
  Problem 1302 - Deepest Leaves Sum

  Runtime - 88 ms
  Memory Usage - 17.9 MB
"""


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def deepestLeavesSum(self, root: TreeNode) -> int:
    if not root:
      return 0

    return self.helper(root, 0)[0]

  def helper(self, node: TreeNode, level: int):
    """
      Recursively, figure out sum of deepest level. Base case is leaf node, in which case return that level and value. For each left and right subtree, return current sum for deeper subtree.
    """
    if not node.left and not node.right:
      # format is (sum, maxLevel)
      return (node.val, level)

    # node is not a leaf node
    a, b = None, None
    # a and b tell us (sum, maxLevel) for respective subTrees
    if node.left:
      a = self.helper(node.left, level + 1)

    if node.right:
      b = self.helper(node.right, level + 1)

      if a is not None:
        if a[1] == b[1]:
          return (a[0] + b[0], a[1])

        if a[1] > b[1]:
          return a

        else:
          return b

      # node.left does not exist. Therefore, return left (sum, maxLevel)
      else:
        return b

    return a
