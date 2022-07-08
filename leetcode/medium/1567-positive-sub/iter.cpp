/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 1567 - Maximum Length of Subarray with Positive Product
 * @approach - An iterative solution with simple branch statements to make sense
 * of mathematical known properties of simple arithmetic multiplication.
 * @date 08-07-2022
 *
 * Runtime - 120 ms
 * Memory Usage - 57.8 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int n = nums.size();

    int currNeg =
        0;  // max len of subarr ending at curr position with negative product
    int currPos = 0;  // max len of subarr ending at curr pos with +ve prod
    int maxLen = 0;   // return value

    for (int i = 0; i < n; i++) {
      // if 0, max subarr len for both min and max will have to be reset to 0
      if (nums[i] == 0) {
        currNeg = 0, currPos = 0;
      }

      // if num is negative
      else if (nums[i] < 0) {
        // if currNeg existed, currNeg and currPos will switch values, and
        // increment them by 1
        if (currNeg) {
          int temp = currNeg;
          currNeg = currPos + 1;
          currPos = temp + 1;
        }
        // if currNeg did not exist, then positive subarray will have 0 length
        // again until a number != 0 is reached
        else {
          currNeg = currPos + 1;
          currPos = 0;
        }
      }

      // if number is positive
      else {
        // if currNeg was not 0, then we increment it by 1
        if (currNeg) {
          currNeg++;
        }
        // we increment currPos by 1 in every case
        currPos++;
      }

      maxLen = max(maxLen, currPos);
    }

    return maxLen;
  }
};

int main() {
  Solution sol = Solution();

  vector<int> a = {1, 2, 3, 5, -6, 4, 0, 10};

  cout << sol.getMaxLen(a) << endl;
}