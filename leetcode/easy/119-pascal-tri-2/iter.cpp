#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> prevRow = {1};
    vector<int> res = {1};

    for (int i = 1; i <= rowIndex; i++) {
      res.resize(i + 1, 1);

      for (int j = 1; j < i; j++) {
        res[j] = prevRow[j - 1] + prevRow[j];
      }

      prevRow = res;
    }

    return res;
  }
};