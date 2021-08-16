/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 96 - Unique BST
 * @date 14-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.2 MB
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  unordered_map<int, int> dp;

  int numTrees(int n)
  {
    if (n <= 1)
      return 1;

    auto itr = dp.find(n);

    if (itr != dp.end())
      return itr->second;

    int left, right;
    int res = 0;

    for (int root = 1; root <= n; root++)
    {
      left = numTrees(root - 1);
      right = numTrees(n - root);
      res += left * right;
    }

    dp.insert({n, res});
    return res;
  }
};