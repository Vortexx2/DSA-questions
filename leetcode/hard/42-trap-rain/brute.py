"""
  @author Vortexx2
  Problem 42 - Trapping Rain Water
  @approach Brute force approach. For each bar in histogram, find out the biggest left and right bar, and use that to calculate the area above the particular bar, if it exists.

  Runtime - TLE
"""
from typing import List


class Solution:
  def trap(self, height: List[int]) -> int:
    arr = []

    for i in range(len(height)):
      temp = [height[i], height[i]]
      j = i - 1
      while j >= 0:
        if (height[j] > temp[0]):
          temp[0] = height[j]
        j -= 1

      k = i + 1
      while k < len(height):
        if (height[k] > temp[1]):
          temp[1] = height[k]
        k += 1

      ht = min(temp[0], temp[1]) - height[i]

      arr.append(ht)

    return sum(arr)
