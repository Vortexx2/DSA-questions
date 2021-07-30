/**
 * @file best-dp.cpp
 * @author Vortexx2
 * @brief Problem 62 - Unique Paths
 * @date 30-07-2021
 * 
 * Runtime - 0 ms O(m * n)
 * Memory Usage - 6.2 MB O(n)
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
  int uniquePaths(int m, int n)
  {
    vector<int> curr(n, 1);

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        curr[j] += curr[j - 1];
      }
    }

    return curr[n - 1];
  }
};