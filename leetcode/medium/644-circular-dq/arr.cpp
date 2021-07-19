/**
 * @file arr.cpp
 * @author Vortexx2
 * @brief Problem 644 - Design Circular Dequeue
 * @approach Using a vector to represent deque
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

class MyCircularDeque
{
public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  vector<int> q;
  int size, front, rear, currSize;
  MyCircularDeque(int k) : q(k), size(k), front(-1), rear(-1)
  {
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value)
  {
    if (isFull())
      return false;

    if (isEmpty())
      front = rear = 0;

    else
      front = (front - 1 + size) % size;

    q[front] = value;

    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value)
  {
    if (isFull())
      return false;

    if (isEmpty())
      front = rear = 0;

    else
      rear = (rear + 1) % size;
    q[rear] = value;

    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront()
  {
    if (isEmpty())
      return false;

    if (front == rear)
      front = rear = -1;

    else
      front = (front + 1) % size;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast()
  {
    if (isEmpty())
      return false;

    if (front == rear)
      front = rear = -1;

    else
      rear = (rear - 1 + size) % size;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront()
  {
    if (isEmpty())
      return -1;
    return q[front];
  }

  /** Get the last item from the deque. */
  int getRear()
  {
    if (isEmpty())
      return -1;
    return q[rear];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty()
  {
    return (front == -1);
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull()
  {
    return ((rear + 1) % size == front);
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */