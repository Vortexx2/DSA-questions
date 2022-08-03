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