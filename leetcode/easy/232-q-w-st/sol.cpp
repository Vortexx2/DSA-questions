/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 232 Queue using Stacks
 * @date 17-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 7.1 MB
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

class MyQueue
{
public:
  /** Initialize your data structure here. */
  stack<int> a, b;
  MyQueue()
  {
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    while (!b.empty()) {
      a.push(b.top());
      b.pop();
    }
    b.push(x);
    
    while (!a.empty()) {
      b.push(a.top());
      a.pop();
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    if (a.empty())
    {
      int top = b.top();
      b.pop();
      return top;
    }
    else
    {
      int top = a.top();
      a.pop();
      return top;
    }
  }

  /** Get the front element. */
  int peek()
  {
    if (a.empty())
      return b.top();

    else
      return a.top();
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return (a.empty() && b.empty());
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
  MyQueue *q = new MyQueue();
  q->push(1);
  q->push(2);
  q->push(3);
  q->push(4);
  
}