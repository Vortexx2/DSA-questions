/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 904 - Fruit Into Baskets
 * @date 13-02-2023
 * 
 * Runtime - 176 ms O(n)
 * Memory Usage - 71.3 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();

    if (n == 1) return 1;

    unordered_map<int, int> counter;
    int left = 0, right = 0;

    int res = 0;

    while (right < n) {
      counter[fruits[right]]++;

      while (counter.size() > 2) {
        counter[fruits[left]]--;

        if (!counter[fruits[left]]) counter.erase(fruits[left]);
        left++;
      }

      res = max(res, right - left + 1);
      right++;
    }

    return res;
  }
};