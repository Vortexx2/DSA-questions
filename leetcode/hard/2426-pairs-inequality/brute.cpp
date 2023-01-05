/**
 * @file brute.cpp
 * @author Vortexx2
 * @brief Problem 2426 - Number of Pairs Satisfying Inequality
 * @date 05-01-2023
 * 
 * Runtime - TLE
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    long long res = 0;

    int n = nums1.size();

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((nums1[i] - nums1[j]) <= (nums2[i] - nums2[j] + diff)) res++;
      }
    }

    return res;
  }
};