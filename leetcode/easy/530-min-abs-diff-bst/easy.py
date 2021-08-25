"""
  @author Vortexx2
  Problem 783 - Minimum Distance in BST

  Runtime - 32 ms
  Memory Usage - 14.1 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def minDiffInBST(self, root: Optional[TreeNode]) -> int:
    inorder = []

    def helper(root: TreeNode) -> None:
      if not root:
        return
      helper(root.left)
      inorder.append(root.val)
      helper(root.right)

    helper(root)

    res = float('inf')
    for i in range(1, len(inorder)):
      res = min(res, inorder[i] - inorder[i - 1])

    return res

