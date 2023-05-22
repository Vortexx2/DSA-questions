/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 347 - Top K Frequent Elements
 * @approach Using a counter and a heap.
 * @date 22-05-2023
 * 
 * Runtime - 15 ms O(n * logn)
 * Memory Usage - 13.7 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // build a counter for each number
    unordered_map<int, int> counter;
    for (int i = 0; i < nums.size(); i++) counter[nums[i]]++;

    auto comp = [&](int a, int b) { return counter[a] >= counter[b]; };

    // add each element to priority queue with weight according to `counter`
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    for (auto it = counter.begin(); it != counter.end(); it++)
      pq.push(it->first);

    // take out top k elements from heap
    vector<int> res(k, 0);
    for (int i = 0; i < k; i++) {
      res[i] = pq.top();
      pq.pop();
    }

    return res;
  }
};