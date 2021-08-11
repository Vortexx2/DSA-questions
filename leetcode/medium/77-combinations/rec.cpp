/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 77 - Combinations
 * @approach Recursive + Backtracking solution
 * @date 11-08-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 9 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<int> path;
    vector<vector<int>> res;
    for (int i = 1; i <= n - k + 1; i++)
      helper(n, k - 1, i, path, res);
    return res;
  }

  void helper(int n, int k, int curr, vector<int> &path, vector<vector<int>> &res)
  {
    path.push_back(curr);
    if (!k)
      res.push_back(path);
    else
    {
      for (int i = curr + 1; i <= n - k + 1; i++)
        helper(n, k - 1, i, path, res);
    }

    path.pop_back();
  }
};