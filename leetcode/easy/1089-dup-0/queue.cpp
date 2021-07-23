/**
 * @file queue.cpp
 * @author Vortexx2
 * @brief Problem 1089 - Duplicate Zeros
 * @date 22-07-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 10 MB
 */
#include <iostream>
#include <vector>
#include <deque>
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
  void duplicateZeros(vector<int> &arr)
  {
    queue<int> q;

    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == 0 || !q.empty())
      {
        q.push(arr[i]);

        if (arr[i] == 0)
          q.push(0);

        arr[i] = q.front();
        q.pop();
      }
    }
  }
};