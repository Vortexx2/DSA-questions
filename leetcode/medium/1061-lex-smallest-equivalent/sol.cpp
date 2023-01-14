/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1061 - Lexicographically Smallest Equivalent String
 * @approach Using an array as a set
 * @date 14-01-2023
 * 
 * Runtime - 0 ms O(n ^ 2)
 * Memory Usage - 6.6 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) { return (int)(c - 'a'); }

char intToChar(int c) { return (char)(c + 'a'); }

class Solution {
 public:
  void fillArr(vector<int> &charArr, int replaceWhat, int replaceWith) {
    for (int i = 0; i < charArr.size(); i++) {
      if (charArr[i] == replaceWhat) charArr[i] = replaceWith;
    }
  }

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();

    vector<int> charArr(26, -1);
    int charCounter = 0;

    for (int i = 0; i < n; i++) {
      int s1Index = charToInt(s1[i]), s2Index = charToInt(s2[i]);

      // no equivalence was previously created with any character, create a new
      // equivalence
      if (charArr[s1Index] == -1 && charArr[s2Index] == -1) {
        charArr[s1Index] = charCounter;
        charArr[s2Index] = charCounter;

        charCounter++;
      }

      // both of them are not -1, i.e. have previous equivalences
      else if (charArr[s1Index] != -1 && charArr[s2Index] != -1) {
        // not badhiya if both of them are not the same
        if (charArr[s1Index] != charArr[s2Index]) {
          // replace all values with equivalence to the other relationship, to
          // make them all the same
          fillArr(charArr, charArr[s1Index], charArr[s2Index]);
        }
      }

      // last case where only one of them was -1. create simple equivalence
      else {
        if (charArr[s1Index] == -1)
          charArr[s1Index] = charArr[s2Index];
        else
          charArr[s2Index] = charArr[s1Index];
      }
    }

    string res = "";

    for (int i = 0; i < baseStr.size(); i++) {
      int original = charArr[charToInt(baseStr[i])];
      int replaceWith = -1;

      // no equivalence existed
      if (original == -1) {
        res.push_back(baseStr[i]);
        continue;
      }

      // equivalence existed
      for (int j = 0; j < charArr.size(); j++) {
        if (charArr[j] == original) {
          replaceWith = j;
          break;
        }
      }

      res.push_back(intToChar(replaceWith));
    }

    return res;
  }
};