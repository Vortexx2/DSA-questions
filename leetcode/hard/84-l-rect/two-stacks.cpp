/**
 * @file two-stacks.cpp
 * @author Vortexx2
 * @brief   Problem 84 - Largest Rectangle in Histogram
 * @approach https://www.youtube.com/watch?v=lsQTYlCiU6c
 * Using two stacks to track indices and heights. Heights is not just the heights[pStack.top()]. Heights
 * stack also has the previous smallest height possible, so as to not have any incompatible heights
 * for the calculated area.
 * @date 09-07-2021
 * 
 * Runtime - 244 ms
 * Memory Usage - 61.5 MB
 */
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    stack<int> pst, hst;
    int currArea = 0, maxArea = 0;
    int lastWidth;

    for (int i = 0; i < heights.size(); i++)
    {
      lastWidth = INT_MAX;

      while (!pst.empty() && heights[i] < hst.top())
      {
        lastWidth = pst.top();
        currArea = (i - pst.top()) * hst.top();
        pst.pop();
        hst.pop();
        maxArea = max(currArea, maxArea);
      }

      if ((pst.empty()) || (heights[i] > hst.top()))
      {
        pst.push(min(i, lastWidth));
        hst.push(heights[i]);
      }
    }

    while (!pst.empty())
    {
      currArea = (heights.size() - pst.top()) * hst.top();
      maxArea = max(currArea, maxArea);
      pst.pop();
      hst.pop();
    }

    return maxArea;
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<int> hist = {2, 1, 5, 6, 2, 3};
  cout << sol->largestRectangleArea(hist);
}