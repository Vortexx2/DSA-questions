/**
 * @file bin.cpp
 * @author Vortexx2
 * @brief Problem 33 - Search In Sorted Array
 * @approach Using 1 binary search according to YT video:
 * https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjq3ePBhvP6AhUZC7cAHbJSAvYQwqsBegQIOhAB&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DU8XENwh8Oy8&usg=AOvVaw2qDiiHlR_YV1mn7tzh9AkY
 * @date 22-10-2022
 *
 * Runtime - 3 ms O(logn)
 * Memory Usage - 11.1 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isLeftPart(vector<int>& nums, int num) { return nums[0] <= num; }

  int search(vector<int>& nums, int target) {
    int l = 0, h = nums.size(), mid;

    while (l < h) {
      mid = (l + h) / 2;

      if (nums[mid] == target)
        return mid;

      else if (nums[mid] < target) {
        if (isLeftPart(nums, nums[mid]))
          l = mid + 1;

        else {
          if (isLeftPart(nums, target))
            h = mid;
          else
            l = mid + 1;
        }
      }

      else {
        if (!isLeftPart(nums, nums[mid]))
          h = mid;

        else {
          if (isLeftPart(nums, target))
            h = mid;

          else
            l = mid + 1;
        }
      }
    }

    return -1;
  }
};