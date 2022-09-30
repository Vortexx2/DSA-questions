/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 821 - Shortest distance to a character
 * @date 30-09-2022
 *
 * Runtime - 3 ms O(n)
 * Memory Usage - 6.8 MB O(n)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    vector<int> ans(s.size(), 0);

    vector<int> occurences;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c) occurences.push_back(i);
    }

    int lastLeft = -1, nextRight = 0;

    for (int i = 0; i < s.size(); i++) {
      if (lastLeft == -1)
        ans[i] = occurences[nextRight] - i;

      else if (nextRight == occurences.size())
        ans[i] = i - occurences[lastLeft];

      else {
        ans[i] =
            min(abs(i - occurences[lastLeft]), abs(occurences[nextRight] - i));
      }

      if (nextRight < occurences.size() && i == occurences[nextRight]) {
        nextRight++;
        lastLeft++;
      }
    }

    return ans;
  }
};

int main() {
  string s = "aaba";
  char c = 'b';
  Solution sol = Solution();

  vector<int> ans = sol.shortestToChar(s, c);

  for (int i = 0; i < ans.size(); i++) {
    printf("%d, ", ans[i]);
  }

  cout << endl;
}