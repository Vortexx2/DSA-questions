/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 509 - Fibonacci number
 * @date 27-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.3 MB
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
  int fib(int n)
  {
    vector<int> dp = {0, 1, 1};

    return helper(n, dp);
  }

  int helper(int n, vector<int> &arr)
  {
    if (n < arr.size())
      return arr[n];

    arr.push_back(helper(n - 1, arr) + helper(n - 2, arr));
    return arr[n];
  }
};