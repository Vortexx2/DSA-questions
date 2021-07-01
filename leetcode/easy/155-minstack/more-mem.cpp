/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 155 - Min Stack
 * @approach Using two stacks with extra space usage on minStack
 * @date 01-07-2021
 * 
 * Runtime - 16 ms
 * Memory Usage - 16.4 MB
 * 
 */
#include <stack>
#include <iostream>

using namespace std;

class MinStack
{
public:
  /** initialize your data structure here. */
  stack<int> st;
  stack<int> minSt;

  MinStack() {}

  void push(int val)
  {
    if (minSt.empty() || val < minSt.top())
    {
      minSt.push(val);
    }
    else
    {
      minSt.push(minSt.top());
    }
    st.push(val);
  }

  void pop()
  {
    st.pop();
    minSt.pop();
  }

  int top()
  {
    return st.top();
  }

  int getMin()
  {
    return minSt.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */