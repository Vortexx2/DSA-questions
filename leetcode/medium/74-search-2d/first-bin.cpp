#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int verticalSearch(vector<vector<int>>& matrix, int target) {
    int targetRow;
    int l = 0, h = matrix.size(), mid;
    while (l < h) {
      mid = (l + h) / 2;

      if (matrix[mid][0] == target) return mid;

      if (target > matrix[mid][0] && target < matrix[mid + 1][0]) return mid;

      if (target < matrix[mid][0]) h = mid;

      if (target > matrix[mid][0]) l = mid + 1;
    }

    return -1;
  }

  bool horizontalSearch(vector<vector<int>>& matrix, int target, int row) {
    int l = 0, h = matrix[0].size();
    int mid;

    while (l < h) {
      mid = (l + h) / 2;

      if (matrix[row][mid] == target)
        return true;

      else if (matrix[row][mid] > target)
        h = mid;

      else
        l = mid + 1;
    }

    return false;
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix[0][0] > target) return false;

    int rows = matrix.size(), cols = matrix[0].size();

    int targetRow;

    if (target >= matrix[rows - 1][0])
      targetRow = rows - 1;

    else {
      targetRow = verticalSearch(matrix, target);
    }

    return horizontalSearch(matrix, target, targetRow);
  }
};

int main() {
  Solution sol = Solution();

  vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  cout << sol.searchMatrix(mat, 15) << endl;
}