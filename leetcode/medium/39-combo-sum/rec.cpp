/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 39 - Combination Sum
 * @date 12-08-2021
 * 
 * Runtime - 12 ms
 * Memory Usage - 10.7 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<int> path;
    vector<vector<int>> res;
    for (int i = 0; i < candidates.size(); i++)
      helper(candidates, target, i, path, res);
    return res;
  }

  void helper(vector<int> &can, int target, int start, vector<int> &path, vector<vector<int>> &res)
  {
    if (target < 0)
      return;

    path.push_back(can[start]);

    if (target == can[start])
      res.push_back(path);

    else
    {
      for (int i = start; i < can.size(); i++)
        helper(can, target - can[start], i, path, res);
    }
    path.pop_back();
  }
};