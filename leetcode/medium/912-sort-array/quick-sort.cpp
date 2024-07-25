/**
 * @file quick-sort.cpp
 * @author Vortexx2
 * @brief Problem 912 - Sort An Array
 * @approach Quick Sort
 * @date 25-07-2024
 * 
 * Runtime - 93 ms O(n log n)
 * Memory Usage - 69.3 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int>& vec) {
  for (auto& n : vec) {
    cout << n << "  ";
  }
  cout << endl;
}


class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();

    quickSort(nums, 0, n - 1);
    return nums;
  }

  void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;

    cout << "l, r: " << l << ", " << r << endl;

    int pivotElement = floor((l + r) / 2);
    cout << "pivot: " << nums[pivotElement] << endl;
    swap(nums[pivotElement], nums[r]);

    int leftElementToSwap = l, rightElementToSwap = r - 1;
    while (leftElementToSwap <= rightElementToSwap) {
      if (nums[leftElementToSwap] > nums[r] && nums[rightElementToSwap] < nums[r]) {
        swap(nums[leftElementToSwap], nums[rightElementToSwap]);
        leftElementToSwap++;
        rightElementToSwap--;
      }

      else {
        if (nums[leftElementToSwap] <= nums[r]) leftElementToSwap++;
        if (nums[rightElementToSwap] >= nums[r]) rightElementToSwap--;
      }
    }

    swap(nums[leftElementToSwap], nums[r]);

    // left recursive call
    quickSort(nums, l, leftElementToSwap - 1);
    // right recursive call
    quickSort(nums, leftElementToSwap + 1, r);
  }
};

int main() {
  vector<int> a = {2, 1, 3};

  Solution sol = Solution();
  sol.sortArray(a);

  printVec(a);
}