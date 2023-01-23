/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 997 - Find The Town Judge
 * @date 23-01-2023
 * 
 * Runtime - 178 ms O(n + e)
 * Memory Usage - 60.8 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);

    for (auto& edge : trust) {
      indegree[edge[1]]++;
      outdegree[edge[0]]++;
    }

    for (int i = 1; i <= n; i++) {
      if ((indegree[i] == n - 1) && outdegree[i] == 0) return i;
    }

    return -1;
  }
};