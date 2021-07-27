/**
 * @file math.cpp
 * @author Vortexx2
 * @brief Problem 509
 * @date 27-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.1 MB
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
#include <cmath>

using namespace std;

class Solution
{
public:
  /**
   * @brief Binet's formula
   * 
   * @param n 
   * @return int 
   */
  int fib(int n)
  {
    float root = pow(5, 0.5);
    float phi = (1 + root) / 2;

    return (int)((pow(phi, n) + 1) / root);
  }
};