"""
  @author Vortexx2
  Problem 173 - BST Iterator

  Runtime - 97 ms
  Memory Usage - 20.3 MB
"""
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class BSTIterator:

  def __init__(self, root: Optional[TreeNode]):
    self.inorder = []
    self.helper(root)
    self.i = -1

  def helper(self, root: TreeNode):
    if not root:
      return
    self.helper(root.left)
    self.inorder.append(root.val)
    self.helper(root.right)

  def next(self) -> int:
    self.i += 1
    return self.inorder[self.i]

  def hasNext(self) -> bool:
    return self.i != len(self.inorder) - 1
