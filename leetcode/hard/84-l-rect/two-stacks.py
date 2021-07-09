from typing import List


class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    max_area, curr_area = 0, 0
    pst, hst = [], []

    for i in range(len(heights)):

      lastwidth = float('inf')

      while ((len(pst)) and (heights[i] < hst[-1])):
        lastwidth = pst[-1]
        curr_area = (i - pst.pop()) * hst.pop()
        max_area = max(max_area, curr_area)

      if ((not len(pst)) or (hst[-1] < heights[i])):
        pst.append(min(lastwidth, i))
        hst.append(heights[i])

    while len(pst):
      curr_area = (len(heights) - pst.pop()) * hst.pop()
      max_area = max(max_area, curr_area)

    return max_area

if __name__ == '__main__':
  sol = Solution()
  print(sol.largestRectangleArea([2,1,5,6,2,3]))