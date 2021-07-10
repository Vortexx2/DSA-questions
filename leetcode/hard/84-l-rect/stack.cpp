/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 84 - Largest Rectangle in Histogram
 * @date 10-07-2021
 * 
 * Runtime - 124 ms
 * Memory Usage - 63.4 MB
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
    if (heights.size() == 1)
      return heights[0];

    int maxArea = 0;
    int h, w;
    stack<int> st;
    heights.push_back(0);
    st.push(-1);

    for (int i = 0; i < heights.size(); i++)
    {
      while (st.top() != -1 && heights[i] < heights[st.top()])
      {
        h = heights[st.top()];
        st.pop();
        w = i - st.top() - 1;
        maxArea = max(maxArea, h * w);
      }

      st.push(i);
    }

    return maxArea;
  }
};

int main()
{
  Solution sol = Solution();
  vector<int> vec = {2, 1, 2};
  cout << sol.largestRectangleArea(vec) << endl;
}