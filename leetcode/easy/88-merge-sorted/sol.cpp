/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 88
 * @date 05-05-2023
 * 
 * Runtime - 3 ms O(m + n)
 * Memory Usage - 9.1 MB O(m)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    // nums1 is empty
    if (!m) { copy(nums2.begin(), nums2.end(), nums1.begin()); return; }

    // nums2 is empty
    if (!n) return;

    vector<int> temp(nums1.begin(), nums1.begin() + m + 1);
    temp[temp.size() - 1] = INT_MAX;
    nums2.push_back(INT_MAX);

    int i = 0, j = 0;
    while (i != m || j != n) {
      if (temp[i] <= nums2[j])
        nums1[( i++ ) + j] = temp[i];
      else
        nums1[i + ( j++ )] = nums2[j];
    }
  }
};