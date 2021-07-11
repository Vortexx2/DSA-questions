/**
 * @file brute.cpp
 * @author Vortexx2
 * @brief Problem 496 - Next Greatest Element I
 * @date 10-07-2021
 * 
 * Runtime - 44 ms
 * Memory Usage - 8.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    bool found = false;
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++)
    {
      res[i] = -1;
      found = false;

      for (int j = 0; j < nums2.size(); j++)
      {
        if (nums1[i] == nums2[j])
        {
          found = true;
        }

        if ((nums1[i] < nums2[j]) && found) {
          res[i] = nums2[j];
          break;
        }
      }
    }

    return res;
  }
};