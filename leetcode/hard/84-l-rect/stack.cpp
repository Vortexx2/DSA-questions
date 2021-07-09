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

    stack<int> st;

    for (int i = 0; i < heights.size(); i++) {

      while (!st.empty() && heights[i] <= heights[st.top()]) {

      }
    }
  }
};