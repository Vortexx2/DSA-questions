/**
 * @file map.cpp
 * @author Vortexx2
 * @brief Problem 496 - Next Greatest Element I
 * @date 10-07-2021
 * 
 * Runtime - 32 ms
 * Memory Usage - 8.4 MB
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> map;
    vector<int> res(nums1.size());

    for (int i = 0; i < nums2.size(); i++) {
      map[nums2[i]] = i;
    }

    for (int i = 0; i < nums1.size(); i++) {
      res[i] = -1;

      for (int j = map[nums1[i]] + 1; j < nums2.size(); j++) {

        if (nums1[i] < nums2[j]) {
          res[i] = nums2[j];
          break;
        }

      }
    }

    return res;
  }
};