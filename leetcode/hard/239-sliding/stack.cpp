/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief 
 * @date 14-07-2021
 * 
 * Runtime - 248 ms
 * Memory Usage - 131.8 MB
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
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    if (!nums.size() || nums.size() == 1 || k == 1)
    {
      return nums;
    }

    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
      while (!dq.empty() && nums[dq.back()] < nums[i])
      {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    for (int i = k; i < nums.size(); i++)
    {
      res.push_back(nums[dq.front()]);

      while (!dq.empty() && nums[dq.back()] < nums[i])
      {
        dq.pop_back();
      }

      while (!dq.empty() && dq.front() + k <= i)
      {
        dq.pop_front();
      }

      dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);

    return res;
  }
};