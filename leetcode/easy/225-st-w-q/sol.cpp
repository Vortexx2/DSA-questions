/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief 
 * @date 17-07-2021
 * 
 * Runtime - 0ms
 * Memory Usage - 6.9 MB
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
  queue<int> a, b;
  MyStack()
  {
  }

  /** Push element x onto stack. */
  void push(int x)
  {
    if (a.empty() && !b.empty()) b.push(x);
    else
      a.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    if (a.empty())
    {
      while (true)
      {
        int top = b.front();
        b.pop();

        if (b.empty())
          return top;

        a.push(top);
      }
    }

    else
    {
      while (true)
      {
        int top = a.front();
        a.pop();

        if (a.empty())
          return top;

        b.push(top);
      }
    }
  }

  /** Get the top element. */
  int top()
  {
    int _top = 0;
    if (a.empty())
    {
      while (!b.empty())
      {
        _top = b.front();
        b.pop();
        a.push(_top);
      }
    }
    else
    {
      while (!a.empty())
      {
        _top = a.front();
        a.pop();
        b.push(_top);
      }
    }

    return _top;
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return (a.empty() && b.empty());
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

int main()
{
  MyStack *obj = new MyStack();
  obj->push(1);
  obj->push(3);
  cout << obj->top() << endl;
}