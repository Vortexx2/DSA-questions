/**
 * @file arr.cpp
 * @author Vortexx2
 * @brief Problem 622 - Design Circular Queue
 * @approach Using a circular array
 * @date 19-07-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 16.8 MB
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

class MyCircularQueue
{
public:
  vector<int> q;
  int front, rear;
  int cap;
  MyCircularQueue(int k) : q(k), front(-1), rear(-1), cap(k) {}

  bool enQueue(int value)
  {
    if (isFull())
      return false;

    if (isEmpty())
    {
      front = rear = 0;
      q[front] = value;
    }

    else
    {
      rear = (rear + 1) % cap;
      q[rear] = value;
    }

    return true;
  }

  bool deQueue()
  {
    if (isEmpty())
    {
      return false;
    }

    if (front == rear)
    {
      front = rear = -1;
    }
    else
      front = (front + 1) % cap;

    return true;
  }

  int Front()
  {
    if (isEmpty())
      return -1;

    return q[front];
  }

  int Rear()
  {
    if (isEmpty())
      return -1;

    return q[rear];
  }

  bool isEmpty()
  {
    return front == -1;
  }

  bool isFull()
  {
    return (rear + 1) % cap == front;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
  MyCircularQueue q = MyCircularQueue(5);
  q.enQueue(1);
  cout << q.Front() << endl;
}