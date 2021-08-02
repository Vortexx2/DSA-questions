/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 63 - Unique Paths II
 * @date 31-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 14.6 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
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
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    if (obstacleGrid.empty())
      return 0;

    if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1])
      return 0;

    unordered_map<string, int> dict;

    return helper(obstacleGrid, dict);
  }

  int helper(vector<vector<int>> &obs, unordered_map<string, int> &dict, int i = 0, int j = 0)
  {
    if (obs[i][j])
      return 0;

    if (i == obs.size() - 1 && j == obs[0].size() - 1)
      return 1;

    string key = to_string(i) + "," + to_string(j);
    auto itr = dict.find(key);

    if (itr != dict.end())
      return itr->second;

    if (i == obs.size() - 1)
      dict[key] = helper(obs, dict, i, j + 1);

    else if (j == obs[0].size() - 1)
      dict[key] = helper(obs, dict, i + 1, j);

    else
      dict[key] = helper(obs, dict, i + 1, j) + helper(obs, dict, i, j + 1);
    return dict[key];
  }
};