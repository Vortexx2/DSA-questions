/**
 * @file math.cpp
 * @author Vortexx2
 * @brief Problem 62 - Unique Paths
 * @date 30-07-2021
 * 
 * Runtime - 0 ms O(m * n)
 * Memory Usage - 5.9 MB O(n)
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
  /**
   * @brief Using combinatorics to solve. We have to make m - 1 D's and n - 1 R's to reach the destination. Therefore formula is (m + n - 2)! / ((m - 1)! * (n - 1)!) 
   * 
   * @param m 
   * @param n 
   * @return int 
   */
  int uniquePaths(int m, int n)
  {
    int minim = min(m - 1, n - 1), maxim = max(m - 1, n - 1);

    long int numerator = 1;

    for (int i = maxim + 1; i <= (minim + maxim); i++)
      numerator *= i;

    int denom = 1;
    for (int i = 2; i <= minim; i++)
      denom *= i;

    return numerator / denom;
  }
};