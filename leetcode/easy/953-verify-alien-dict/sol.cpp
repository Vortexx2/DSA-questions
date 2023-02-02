/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 953 - Verify an Alien Dictionary
 * @date 02-02-2023
 * 
 * Runtime - 3 ms O(n * m)
 * Memory Usage - 9.3 MB
 */
#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) {
  if (c == '$') return 0;
  return (int)(c - 'a') + 1;
}

class Solution {
 public:
  vector<int> counter = vector<int>(27, 0);

  void fillCounter(string& order) {
    for (int i = 0; i < 26; i++) counter[charToInt(order[i])] = i + 1;
  }

  bool firstWordSmaller(string& a, string& b) {
    int minLength = min(a.size(), b.size());

    for (int i = 0; i < minLength; i++) {
      if (counter[charToInt(a[i])] < counter[charToInt(b[i])]) return true;

      if (counter[charToInt(a[i])] > counter[charToInt(b[i])]) return false;
    }

    return a.size() <= b.size();
  }

  bool isAlienSorted(vector<string>& words, string order) {
    fillCounter(order);

    for (int i = 1; i < words.size(); i++) {
      if (!firstWordSmaller(words[i - 1], words[i])) return false;
    }

    return true;
  }
};