"""
  @author Vortexx2
  Problem 1339 - Maximum Product of a Splitted BT

  Runtime - 420 ms
  Memory Usage - 88.2 MB
"""
from typing import Dict, Optional


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def maxProduct(self, root: Optional[TreeNode]) -> int:
    dic = {}
    self.writeSumOfSubtrees(root, dic)
    maxProd = 0

    def helper(fRoot: TreeNode, sRoot: TreeNode):
      if not sRoot:
        return 0
      prod = dic[sRoot] * (dic[fRoot] - dic[sRoot])
      childProd = max(helper(fRoot, sRoot.left), helper(fRoot, sRoot.right))
      return max(prod, childProd)

    maxProd = max(helper(root, root.left), helper(root, root.right))

    return int(maxProd % (1e9 + 7))

  def writeSumOfSubtrees(self, root: TreeNode, dic: Dict) -> None:
    if not root:
      return 0
    dic[root] = self.writeSumOfSubtrees(
        root.left, dic) + self.writeSumOfSubtrees(root.right, dic) + root.val
    return dic[root]
