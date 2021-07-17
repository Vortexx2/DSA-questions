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
  stack<int> in, out;
  MyQueue()
  {
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    in.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    peek();
    int ans = out.top();
    out.pop();
    return ans;
  }

  /** Get the front element. */
  int peek()
  {
    if (!out.empty()) {
      return out.top();
    }
    
    while (!in.empty())
    {
      out.push(in.top());
      in.pop();
    }
    return out.top();
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return (in.empty() && out.empty());
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