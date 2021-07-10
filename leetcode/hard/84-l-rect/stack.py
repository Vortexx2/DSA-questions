"""
  @author Vortexx2
  Problem 84 - Largest Rectangle in Histogram
  @approach Using a stack to track positions of the index each position

  Runtime - 1100 ms
  Memory Usage - 27.2 MB
"""
from typing import List


class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    # append 0 to heights list so as to have one last iteration where you clear out the stack
    heights.append(0)
    # keep -1, so heights[st[-1]] in the base case will have a rectangle of height 0
    st = [-1]
    maxArea = 0

    for i in range(len(heights)):

      # you don't even need to have a case for (len(st) != 0), since heights[i] < heights[-1],
      # where -1 is always at the end of `st`
      while (heights[i] < heights[st[-1]]):
        # curr height would be the height corresponding to index on top of stack
        h = heights[st.pop()]
        # width can be calculated using one index less than the needed index
        w = i - st[-1] - 1
        maxArea = max(maxArea, h * w)

      # we append each index to the stack
      st.append(i)

    heights.pop()
    return maxArea


if __name__ == '__main__':
  sol = Solution()
  print(sol.largestRectangleArea([2, 1, 2]))
