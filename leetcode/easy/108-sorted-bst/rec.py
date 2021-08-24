"""
  @author Vortexx2
  Problem 108 - Sorted Array Into BST

  Runtime - 56 ms
  Memory Usage - 15.5 MB
"""
# Definition for a binary tree node.


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
    mn, mx = 0, len(nums)

    def construct(mn: int, mx: int, nums: List[int]) -> TreeNode:
      if mn >= mx:
        return None

      i = (mn + mx) // 2

      root = TreeNode(nums[i])
      root.left = construct(mn, i, nums)
      root.right = construct(i + 1, mx, nums)
      return root

    return construct(mn, mx, nums)
