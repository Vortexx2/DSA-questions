/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 4 - Median Of Two Sorted Arrays
 * @approach Using two pointers and incrementing each one if it is smaller than the other element, enabling us to store a sorted array in a third vector. Then, a simple median can be taken.
 * @date 18-07-2021
 * 
 * Runtime - 24 ms
 * Memory Usage - 90.2 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    double res;
    vector<int> arr;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] < nums2[j])
      {
        arr.push_back(nums1[i]);
        i++;
      }

      else
      {
        arr.push_back(nums2[j]);
        j++;
      }
    }

    while (j < nums2.size())
    {
      arr.push_back(nums2[j]);
      j++;
    }

    while (i < nums1.size())
    {
      arr.push_back(nums1[i]);
      i++;
    }

    int temp = arr.size() / 2;
    if (arr.size() % 2 == 0)
    {
      return (((double)arr[temp - 1] + arr[temp]) / 2);
    }

    return (double)(arr[temp]);
  }
};
