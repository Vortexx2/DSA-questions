from typing import List


# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def binaryTreePaths(self, root: TreeNode) -> List[str]:
    if not root:
      return []

    arr, curr = [], []
    self.helper(root, arr, curr)
    for i in range(len(arr)):
      arr[i] = "->".join(str(num) for num in arr[i])
    return arr

  def helper(self, node: TreeNode, arr: List[str], curr: str) -> None:

    if not node:
      return

    curr.append(node.val)
    if not node.left and not node.right:
      arr.append(curr.copy())

    else:
      self.helper(node.left, arr, curr)
      self.helper(node.right, arr, curr)

    curr.pop()
