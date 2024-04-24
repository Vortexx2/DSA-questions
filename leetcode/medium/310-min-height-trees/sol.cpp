/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 310 - Minimum Height Trees
 * @approach Using a BFS topological sort type approach
 * @date 24-04-2024
 *
 * Runtime - 110 ms
 * Memory Usage - 61.56 MB
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n, vector<int>());

        unordered_map<int, int> degrees;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        queue<int> bfs;
        for (auto it = degrees.begin(); it != degrees.end(); it++) {
            if (it->second == 1) bfs.push(it->first);
        }

        while (n > 2) {
            int itemsInBFS = bfs.size();

            while (itemsInBFS) {
                int front = bfs.front();
                bfs.pop();
                degrees[front]--;

                n--;
                for (auto& nxt : adj[front]) {
                    if (--degrees[nxt] == 1) bfs.push(nxt);
                }

                itemsInBFS--;
            }
        }

        vector<int> res;
        while (!bfs.empty()) {
            res.push_back(bfs.front());
            bfs.pop();
        }

        return res;
    }
};