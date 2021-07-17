/**
 * @file one-q.cpp
 * @author Vortexx2
 * @brief Problem 225 - Stack Using One Queue
 * @approach Using 1 queue to implement a stack
 * @date 17-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.7 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class MyStack
{
public:
  /** Initialize your data structure here. */
  queue<int> q;
  MyStack()
  {
  }

  /** Push element x onto stack. */
  void push(int x)
  {
    q.push(x);

    int temp;
    if (!q.empty())
    {
      for (int i = 0; i < q.size() - 1; i++)
      {
        temp = q.front();
        q.pop();
        q.push(temp);
      }
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    int ret = q.front();
    q.pop();
    return ret;
  }

  /** Get the top element. */
  int top()
  {
    return q.front();
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */