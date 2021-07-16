"""
  @author Vortexx2

  Runtime - 52 ms
  Memory Usage - 14.9 MB
"""
from typing import List


class Solution:
  def trap(self, height: List[int]) -> int:
    """
      Always use a stack to store something in order of relevance. Here we use the stack
      to store those indices in a descending order. If we encounter a height > 
      than previous n stored indices, we keep on popping them adding the respective
      areas. This method figures out the left and right boundary, allowing us to
      calculate the height seamlessly. 
    """
    top = 0
    st = []
    area = 0

    for i in range(len(height)):

      while (len(st) and height[i] > height[st[-1]]):
        # top is the height enveloped by 2 greater heights on both sides
        top = st.pop()

        if not len(st):
          break
        
        # this is the dist between the right boundary and the left boundary
        dist = i - st[-1] - 1
        # height with which to calculate the area would be the min of left and right boundary
        ht = min(height[i], height[st[-1]]) - height[top]
        area += dist * ht

      st.append(i)

    return area


if __name__ == '__main__':
  sol = Solution()
  print(sol.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
