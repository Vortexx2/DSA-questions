/**
 * @file slow.cpp
 * @author Vortexx2
 * @brief Problem 901 - Online Stock Span
 * @approach O(n ^ 2)
 * @date 07-07-2021
 * 
 * Runtime - 1228 ms
 * Memory Usage - 86.1 MB
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner
{
public:
  vector<int> a;
  StockSpanner()
  {
  }

  int next(int price)
  {
    a.push_back(price);

    if (a.size() == 1) return 1;

    for (int i = a.size() - 2; i >= 0; i--) {
      if (a[i] > price) {
        return (a.size() - i - 1);
      }
    }

    return a.size();
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */