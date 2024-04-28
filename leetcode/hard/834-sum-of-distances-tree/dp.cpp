/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 834 - Sum of Distances in Tree
 * @date 28-04-2024
 *
 * Runtime - 973 ms
 * Memory Usage - 146.77 MB
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> closer_nodes;
    vector<int> res;
    int n;

    int dfs1(int currNode, map<int, vector<int>>& graph, set<int>& visited) {
        if (visited.find(currNode) != visited.end()) return 0;

        visited.insert(currNode);

        int allChildren = 1;  // this includes currNode as well
        for (auto& child : graph[currNode]) {
            int numChildren = dfs1(child, graph, visited);
            allChildren += numChildren;
            res[0] += numChildren;
        }

        closer_nodes[currNode] = allChildren;
        return allChildren;
    }

    void dfs2(int currNode, int prevNode, map<int, vector<int>>& graph,
              set<int>& visited) {
        if (visited.find(currNode) != visited.end()) return;

        visited.insert(currNode);

        if (currNode != 0)
            res[currNode] = res[prevNode] - closer_nodes[currNode] +
                            (n - closer_nodes[currNode]);

        for (auto& child : graph[currNode]) {
            dfs2(child, currNode, graph, visited);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;

        closer_nodes = vector<int>(n, 0), res = vector<int>(n, 0);
        this->n = n;

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        set<int> visited;
        dfs1(0, graph, visited);

        visited = {};

        dfs2(0, -1, graph, visited);
        return res;
    }
};