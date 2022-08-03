/**
 * @file best-iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 63 - Unique Paths 2
 * Using a tabulation DP approach with the least memory needed to store the DP information
 * @date 03-08-2022
 * 
 * Runtime - 6 ms
 * Memory Usage - 7.7 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      
      int rows = obstacleGrid.size(), cols = obstacleGrid[0].size(); 
      
      if (obstacleGrid[0][0] || obstacleGrid[rows - 1][cols - 1]) return 0;
      
      // position (0, 0) can't be an obstacle
      vector<int> row(cols, 0);
      
      // therefore
      row[0] = 1;
      
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (obstacleGrid[i][j]) { 
            row[j] = 0;
            continue;
          }
          
          if (j != 0) {
            row[j] += row[j - 1];
          }
        }
      }
      
      return row[cols - 1];
    }
};