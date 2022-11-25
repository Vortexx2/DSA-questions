/**
 * @file bfs-topological.cpp
 * @author Vortexx2
 * @brief Problem 207 - Course Schedule
 * @approach Using BFS topological sorting
 * @date 25-11-2022
 * 
 * Runtime - 25 ms O(n + e)
 * Memory Usage - 13.1 MB O(n + e)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> degree(numCourses, 0);
    queue<int> bfs;

    int numExplored = 0;

    for (auto& p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      degree[p[0]] += 1;
    }

    for (int i = 0; i < numCourses; i++)
      if (!degree[i]) bfs.push(i);

    while (!bfs.empty()) {
      int toExplore = bfs.front();
      bfs.pop();

      for (auto& vertex : graph[toExplore]) {
        if (--degree[vertex] == 0) bfs.push(vertex);
      }

      numExplored++;
    }

    return numExplored == numCourses;
  }
};