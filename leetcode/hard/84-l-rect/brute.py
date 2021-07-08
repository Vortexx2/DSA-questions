"""
  @author Vortexx2
  Problem 84 - Largest Rectangle in Histogram

  Brute force solution which times out
"""
from typing import List


class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    max_area = 0

    for i in range(len(heights)):
      min_height = heights[i]

      for j in range(i, len(heights)):
        min_height = min(min_height, heights[j])
        curr_area = (j - i + 1) * min_height
        max_area = max(max_area, curr_area)

    return max_area
