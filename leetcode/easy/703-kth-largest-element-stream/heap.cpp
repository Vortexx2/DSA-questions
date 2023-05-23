/**
 * @file heap.cpp
 * @author Vortexx2
 * @brief Problem 703 - kth largest element stream
 * @approach Using priority queue
 * @date 23-05-2023
 * 
 * Runtime - 40 ms O(n * log k) for initialisation and O(log k) for adding new element
 * Memory Usage - O(k)
 */
#include <bits/stdc++.h>

using namespace std;

class KthLargest {
 public:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

  KthLargest(int k, vector<int>& nums) {
    this->k = k;

    for (auto& num : nums) {
      pq.push(num);
      if (pq.size() > k) pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > k) pq.pop();

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */