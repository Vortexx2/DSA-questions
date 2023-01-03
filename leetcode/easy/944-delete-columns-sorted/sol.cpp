/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 944 - Delete Columns to Make Sorted
 * @date 03-01-2023
 * 
 * Runtime - 80 ms O(m * n)
 * Memory Usage - 12.2 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int len = strs[0].size();

    int numDeletions = 0;

    for (int i = 0; i < len; i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] < strs[j - 1][i]) {
          numDeletions++;
          break;
        }
      }
    }

    return numDeletions;
  }
};