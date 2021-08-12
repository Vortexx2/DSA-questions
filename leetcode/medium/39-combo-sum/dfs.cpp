/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 39 - Combination Sum
 * @date 12-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 11.2 MB
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
    sort(candidates.begin(), candidates.end());

    dfs(candidates, target, path, 0, res);
    return res;
  }

  void dfs(vector<int> &cand, int target, vector<int> &path, int index, vector<vector<int>> &res)
  {
    if (!target)
    {
      res.push_back(path);
      return;
    }

    vector<int> co;
    for (int i = index; i < cand.size(); i++)
    {
      if (target < cand[i])
        return;

      co = path;
      co.push_back(cand[i]);

      dfs(cand, target - cand[i], co, i, res);
    }
  }
};