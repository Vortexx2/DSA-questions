/**
 * @file bfs-topological.cpp
 * @author Vortexx2
 * @brief Problem 210 - Course Schedule 2
 * @approach Using bfs topological sort
 * @date 25-11-2022
 * 
 * Runtime - 24 ms O(n + e)
 * Memory Usage - 13.2 MB O(n + e)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> bfs, degree(numCourses, 0);

    for (auto& p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      degree[p[0]] += 1;
    }

    for (int i = 0; i < numCourses; i++)
      if (!degree[i]) bfs.push_back(i);

    for (int i = 0; i < bfs.size(); i++) {
      for (auto& vertex : graph[bfs[i]]) {
        if (--degree[vertex] == 0) bfs.push_back(vertex);
      }
    }

    if (bfs.size() == numCourses) return bfs;

    return {};
  }
};