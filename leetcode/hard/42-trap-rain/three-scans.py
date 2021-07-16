"""
  @author Vortexx2

  Runtime - 56 ms
  Memory Usage - 14.8 MB
"""
from typing import List
from collections import deque


class Solution:
  def trap(self, height: List[int]) -> int:
    if (not len(height) or len(height) == 1 or len(height) == 2):
      return 0

    lefts, rights = height.copy(), height.copy()
    max_ht = height[0]

    for i in range(len(height)):
      lefts[i] = max_ht

      if height[i] > max_ht:
        max_ht = height[i]

    max_ht = height[-1]
    for i in range(len(height) - 1, -1, -1):
      rights[i] = max_ht

      if height[i] > max_ht:
        max_ht = height[i]

    curr_area = 0

    for i in range(len(height)):
      area = min(lefts[i], rights[i]) - height[i]
      curr_area += area if (area > 0) else 0

    return curr_area


if __name__ == '__main__':
  sol = Solution()
  print(sol.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
