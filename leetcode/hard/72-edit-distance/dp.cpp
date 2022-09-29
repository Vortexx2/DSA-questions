/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 72 - Edit Distance
 * @date 29-09-2022
 * 
 * Runtime - 15 ms O(n ^ 2)
 * Memory Usage - 9.1 MB O(n ^ 2)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @brief Operations allowed: Insert a character, delete a character, replace
   * a character
   *
   * @param word1
   * @param word2
   * @return int
   */
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    fillInitialValues(dp);

    // loop goes row wise
    for (int i = m - 1; i >= 0; i--) {
      // inner loop goes column wise, from end to the front
      for (int j = n - 1; j >= 0; j--) {
        if (word1[i] == word2[j]) {
          dp[i][j] = dp[i + 1][j + 1];
        }

        // if first letter of both substrings are not equal
        else {
          dp[i][j] = min(dp[i][j + 1] + 1,
                         min(dp[i + 1][j] + 1, 1 + dp[i + 1][j + 1]));

          // BELOW SECTION IS NOT NEEDED
          // length of both substrings are equal
          // if ((m - i) == (n - j)) {
          //   // minimum length to switch between 2 equal substrings is either:
          //   // 1. delete first element from the 2 substrings and see sol of
          //   // subproblem
          //   // 2. replace each character by the correct one i.e. cost = length
          //   // of substring (m - i)
          //   dp[i][j] = min(dp[i][j], (m - i));
          // }
        }
      }
    }

    print2D(dp, word1, word2);

    return dp[0][0];
  }

  void fillInitialValues(vector<vector<int>> &dp) {
    int rows = dp.size(),     // no of rows
        cols = dp[0].size();  // no of cols

    for (int i = 0; i < rows; i++) {
      dp[i][cols - 1] = rows - i - 1;
    }

    for (int i = 0; i < cols; i++) {
      dp[rows - 1][i] = cols - i - 1;
    }
  }

  void print2D(vector<vector<int>> &dp, string &word1, string &word2) {
    cout << " \t";

    for (int i = 0; i < dp[0].size(); i++) {
      cout << word2[i] << '\t';
    }

    cout << endl;

    for (int i = 0; i < dp.size(); i++) {
      cout << word1[i] << '\t';
      for (int j = 0; j < dp[0].size(); j++) {
        cout << dp[i][j] << '\t';
      }

      cout << endl;
    }
  }
};

int main() {
  Solution sol = Solution();
  string s1 = "abcdxabcde";
  string s2 = "abcdeabcdx";
  // string s1 = "horse";
  // string s2 = "ros";

  cout << sol.minDistance(s1, s2) << endl;
}