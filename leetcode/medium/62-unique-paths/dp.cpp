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
  unordered_map<string, int> dp;
  int uniquePaths(int m, int n)
  {
    if (m == 0 || n == 0)
      return 0;
    if (m == 1 || n == 0)
      return 1;

    string key = to_string(m) + "," + to_string(n);
    auto itr = dp.find(key);

    if (itr != dp.end())
      return itr->second;

    dp[key] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    return dp[key];
  }
};