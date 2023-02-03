/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 6 - Zigzag Conversion
 * @date 03-02-2023
 * 
 * Runtime - 27 ms
 * Memory Usage - 14.3 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    vector<vector<char>> res(numRows);

    int i = 0, n = s.size();

    while (i < n) {
      int currRow = 0;
      // fills in straight column
      while (i < n && currRow < numRows) {
        res[currRow].push_back(s[i]);
        i++;
        currRow++;
      }

      // proceed to go diagonally upwards
      currRow = numRows - 2;
      while (i < n && currRow >= 1) {
        res[currRow].push_back(s[i]);
        currRow--;
        i++;
      }
    }

    string ans;
    // compress matrix into string
    for (int i = 0; i < numRows; i++) {
      ans += string(res[i].begin(), res[i].end());
    }

    return ans;
  }
};