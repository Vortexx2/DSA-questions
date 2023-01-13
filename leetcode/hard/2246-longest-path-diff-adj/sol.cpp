/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2246 - Longest Path with Different Adjacent Characters
 * @approach using an adjacency matrix
 * @date 13-01-2023
 * 
 * Runtime - 1032 ms
 * Memory Usage - 318.2 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  unordered_map<int, set<int>> adj;
  int res;

  void fillAdj(vector<int>& parent) {
    for (int i = 1; i < parent.size(); i++) {
      int parentNode = parent[i], childNode = i;

      while (parentNode != -1) {
        // the subtree from this point onwards exists in the adj list
        if (adj[parentNode].find(childNode) != adj[parentNode].end()) break;

        adj[parentNode].insert(childNode);
        childNode = parentNode;
        parentNode = parent[parentNode];
      }
    }
  }

  int helper(int curr, string& s) {
    int currMax = 1;

    int firstLargest = 0, secondLargest = 0;

    for (auto& child : adj[curr]) {
      auto subLargest = helper(child, s);

      // if adjacent characters are the same, we only take the max as the one
      // that is possible in that subtree, and we do not include `curr` in path
      // length calculations
      if (s[curr] == s[child]) {
        res = max(res, subLargest);
      }

      else {
        currMax = max(currMax, subLargest + 1);

        if (subLargest > firstLargest) {
          secondLargest = firstLargest;
          firstLargest = subLargest;
        }

        else if (subLargest > secondLargest)
          secondLargest = subLargest;
      }
    }

    res = max(max(res, currMax), firstLargest + secondLargest + 1);
    return currMax;
  }

  int longestPath(vector<int>& parent, string s) {
    fillAdj(parent);

    res = 1;

    return max(res, helper(0, s));
  }
};