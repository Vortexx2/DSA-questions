/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 274 - H Index
 * @approach Using presorting
 * @date 08-05-2023
 * 
 * Runtime - 3 ms O(n * logn)
 * Memory Usage - 8.5 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<>());

    int n = citations.size();
    int res = 0;

    for (int i = 0; i < n; i++) {
      res = max(res, min(citations[i], i + 1));
    }

    return res;
  }
};