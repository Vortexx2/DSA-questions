/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 299 - Bulls and Cows
 * @approach Using hash maps
 * @date 31-12-2022
 * 
 * Runtime - 4 ms O(n)
 * Memory Usage - 6.8 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    // maps count of possible cows in secret and guess
    unordered_map<char, int> secretCows, guessCows;

    int bulls = 0, cows = 0;

    for (int i = 0; i < secret.size(); i++) {
      if (secret[i] == guess[i]) bulls++;

      // possibility of cow
      else {
        if (secretCows[guess[i]]) {
          cows++;
          secretCows[guess[i]]--;
        }

        else
          guessCows[guess[i]]++;

        if (guessCows[secret[i]]) {
          cows++;
          guessCows[secret[i]]--;
        }

        else
          secretCows[secret[i]]++;
      }
    }

    string res = to_string(bulls) + "A" + to_string(cows) + "B";
    return res;
  }
};