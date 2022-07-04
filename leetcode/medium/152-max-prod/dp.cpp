/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 152 - Max Product Subarray
 * @approach
 * @date 04-07-2022
 *
 * Runtime - 7 ms
 * Memory Usage - 13.8 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    // keep 2 variables for minimum current product and maximum current product.
    // like DP in kadane's algorithm
    // minCurr and maxCurr are the minimum and maximum products of subarrays
    // from start to that element, where the current element is included.
    // maxProd is the maximum subarray product that has been encountered up to
    // that point.
    int minCurr, maxCurr, maxProd;
    minCurr = maxCurr = maxProd = nums[0];

    for (int i = 1; i < n; i++) {
      int minTemp = minCurr * nums[i], maxTemp = maxCurr * nums[i];

      // if number was negative, maxCurr can be transformed into minCurr by multiplying the current number
      minCurr = min(minTemp, min(maxTemp, nums[i]));
      // similar to the above, minCurr can be transformed into maxCurr 
      maxCurr = max(maxTemp, max(minTemp, nums[i]));

      maxProd = max(maxProd, maxCurr);
    }

    return maxProd;
  }
};