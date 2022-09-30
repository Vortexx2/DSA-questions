/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 860 - Lemonade Change
 * @date 30-09-2022
 * 
 * Runtime - 109 ms O(n)
 * Memory Usage - 83.5 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    if (bills[0] != 5) return false;

    vector<int> notes = {0, 0, 0};

    for (int i = 0; i < bills.size(); i++) {
      if (bills[i] == 5) {
        notes[0] += 1;
      }

      else if (bills[i] == 10) {
        if (!notes[0]) return false;

        notes[0] -= 1;
        notes[1] += 1;
      }

      else {
        notes[2] += 1;
        if (!notes[0]) return false;

        if (notes[1]) {
          notes[0] -= 1;
          notes[1] -= 1;
        }

        else if (notes[0] < 3) {
          return false;
        }

        else {
          notes[0] -= 3;
        }
      }
    }

    return true;
  }
};