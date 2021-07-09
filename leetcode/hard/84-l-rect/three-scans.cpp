/**
 * @file three-scans.cpp
 * @author Vortexx2
 * @brief   Problem 84 - Largest Rectangle in Histogram
  @approach First two scans to store all info about left and right limits about the closest
  indices for elements having lesser height than it.
 * @date 09-07-2021
 * 
 * Runtime - 208 ms
 * Memory Usage - 66.4 MB
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    vector<int> st;
    vector<int> left(heights.size(), 0), right(heights.size(), heights.size() + 1);

    for (int i = 0; i < heights.size(); i++)
    {
      while (!st.empty() && heights[i] <= heights[st.back()])
      {
        st.pop_back();
      }

      if (!st.empty())
      {
        left[i] = st.back() + 1;
      }

      st.push_back(i);
    }

    st.clear();

    for (int i = heights.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && heights[i] <= heights[st.back()])
      {
        st.pop_back();
      }

      if (!st.empty())
      {
        right[i] = st.back() + 1;
      }

      st.push_back(i);
    }

    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++)
    {
      maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);
    }

    return maxArea;
  }
};