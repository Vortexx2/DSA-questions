/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 583 - Delete Operation for Two Strings
 * @approach Using a bottom up recursive approach
 * @date 22-12-2022
 * 
 * Runtime - 16 ms O(M * N)
 * Memory Usage - 11.6 MB O(M)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    vector<int> prev(word2.size() + 1), curr(word2.size() + 1);

    fillInitial(prev);

    for (int i = 1; i <= word1.size(); i++) {
      curr[0] = i;

      for (int j = 1; j <= word2.size(); j++) {
        // if current letter for both words are the same
        if (word1[i - 1] == word2[j - 1]) curr[j] = prev[j - 1];

        // if current letters are not the same
        else
          curr[j] = min(curr[j - 1], prev[j]) + 1;
      }

      prev = curr;
      curr = vector<int>(word2.size() + 1);
    }

    return prev[word2.size()];
  }

  void fillInitial(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = i;
    }
  }
};