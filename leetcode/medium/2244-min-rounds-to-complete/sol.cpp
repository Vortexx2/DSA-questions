/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2244 - Minimum Rounds to Complete All Tasks
 * @date 04-01-2023
 *
 * Runtime - 358 ms O(n)
 * Memory Usage - 104.6 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int calculateMinRounds(int count) {
    if (count == 1) return -1;

    if (count % 3 == 0) return count / 3;

    return (count / 3) + 1;
  }

  int minimumRounds(vector<int>& tasks) {
    map<int, int> counter;

    for (auto& num : tasks) {
      counter[num]++;
    }

    int ans = 0;
    for (auto it = counter.begin(); it != counter.end(); it++) {
      // if difficulty is 1, not possible
      if (it->second == 1) return -1;

      ans += calculateMinRounds(it->second);
    }

    return ans;
  }
};