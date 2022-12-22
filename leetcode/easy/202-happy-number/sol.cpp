/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 202 - Happy Number
 * @approach Using number theory
 * @date 22-12-2022
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.3 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  set<int> isPossible;

  bool isHappy(int n) {
    set<int> visited;

    int temp = n;

    while (visited.find(temp) == visited.end()) {
      if (temp == 1) {
        isPossible.insert(temp);
        return true;
      }

      visited.insert(temp);
      temp = sumOfSquaresDigits(temp);
    }

    return false;
  }

  int sumOfSquaresDigits(int n) {
    int res = 0;
    int rem;

    while (n) {
      rem = n % 10;
      
      res += (rem * rem);
      n /= 10;
    }

    return res;
  }
};