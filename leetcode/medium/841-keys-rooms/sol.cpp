/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 841 - Keys And Rooms
 * @approach Using a simple BFS approach
 * @date 17-11-2022
 * 
 * Runtime - 16 ms O(n ^ 2)
 * Memory Usage - 10.6 MB O(n)
 */
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    queue<int> keys;
    keys.push(0);

    unordered_map<int, bool> visited;

    int numVisited = 0;

    int currRoom;
    while (!keys.empty()) {
      currRoom = keys.front();
      keys.pop();

      if (visited[currRoom]) continue;

      visited[currRoom] = true;
      numVisited++;

      for (auto& r : rooms[currRoom]) {
        if (visited[r]) continue;

        // if room has not been visited before
        keys.push(r);
      }

      if (numVisited == rooms.size()) return true;
    }

    return false;
  }
};