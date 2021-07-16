/**
 * @file three-scans.cpp
 * @author Vortexx2
 * @brief Problem 42 - Trapping Rain Water
 * @date 16-07-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 14.1 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    if (height.empty() || height.size() == 1 || height.size() == 2)
      return 0;

    vector<int> lefts(height), rights(height);

    int maxHt = 0;
    for (int i = 0; i < height.size(); i++)
    {
      if (maxHt > height[i])
        lefts[i] = maxHt;

      else
        maxHt = height[i];
    }

    maxHt = 0;

    for (int i = height.size() - 1; i >= 0; i--)
    {
      if (maxHt > height[i])
        rights[i] = maxHt;
      else
        maxHt = height[i];
    }

    int currArea = 0;
    int area = 0;
    for (int i = 0; i < height.size(); i++)
    {
      area = min(lefts[i], rights[i]) - height[i];

      if (area > 0)
        currArea += area;
    }

    return currArea;
  }
};
