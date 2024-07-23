/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1636 - Sort Array By Increasing Frequency
 * @date 24-07-2024
 * 
 * Runtime - 7 ms O(n * logn)
 * Memory Usage - 15.18 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Compare {
 public:
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    if (a.second < b.second) return true;

    if (a.second == b.second && a.first > b.first) return true;

    return false;
  }
};

class Solution {
 public:
  vector<int> frequencySort(vector<int> &nums) {
    // we will insert (num, freq) into this PQ
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    // this contains the frequency count for each unique item
    unordered_map<int, int> freqCount;
    for (auto &n : nums) {
      freqCount[n]++;
    }

    for (auto it = freqCount.begin(); it != freqCount.end(); it++) {
      pq.push({it->first, it->second});
    }

    vector<int> res(nums.size(), 0);
    int i = 0;
    while (!pq.empty()) {
      int num, count;
      tie(num, count) = pq.top();

      while (count--) {
        res[i++] = num;
      }
      pq.pop();
    }

    return res;
  }
};