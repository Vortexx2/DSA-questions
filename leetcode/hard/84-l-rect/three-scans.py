"""
  @author Vortexx2
  Problem 84 - Largest Rectangle in Histogram
  @approach First two scans to store all info about left and right limits about the closest
  indices for elements having lesser height than it.

  Runtime - 1052 ms
  Memory Usage - 28.9 MB
"""
from typing import List


class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:

    st = []
    # left stores the index of the closest left element where the height is lesser than current
    # right stores the index of the closest right element where the height is lesser than current
    left, right = [0] * len(heights), [len(heights) + 1] * len(heights)

    # go forward to find the last left element < curr ht.
    for i in range(len(heights)):

      while (len(st) and (heights[i] <= heights[st[-1]])):
        st.pop()

      if len(st):
        left[i] = st[-1] + 1

      st.append(i)

    st = []

    # go backward to find the last right element < curr ht.
    for i in range(len(heights) - 1, -1, -1):

      while (len(st) and (heights[i] <= heights[st[-1]])):
        st.pop()

      if len(st):
        right[i] = st[-1] + 1

      st.append(i)

    max_area = 0

    # go through one last time to calculate each area for all bars of histogram
    for i in range(len(heights)):
      max_area = max(max_area, (right[i] - left[i] - 1) * heights[i])

    return max_area


if __name__ == '__main__':
  sol = Solution()
  print(sol.largestRectangleArea([2, 1, 5, 6, 2, 3]))
