/**
 * @file stacks.cpp
 * @author Vortexx2
 * @brief Problem 901 - Online Stock Spans
 * @approach Using stacks to keep track of price before current price which was lesser than
 * current price. 
 * @date 07-07-2021
 * 
 * Runtime - 192 ms
 * Memory Usage - 86.4 MB 
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner
{
public:
  /**
   * @brief Stores indices of each element.
   */
  stack<int> st;

  /**
   * @brief Stores each price occurring up to that price.
   */
  vector<int> vec;
  StockSpanner()
  {
  }

  int next(int price)
  {
    int P;
    vec.push_back(price);

    // This loop is to pop each element in stack which had value lesser than current `price`
    while (!st.empty() && (price >= vec[st.top()]))
    {
      st.pop();
    }

    if (st.empty())
    {
      P = -1;
    }

    else
    {
      P = st.top();
    }
    st.push(vec.size() - 1);

    return vec.size() - 1 - P;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */