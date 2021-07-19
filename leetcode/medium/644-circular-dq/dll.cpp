/**
 * @file dll.cpp
 * @author Vortexx2
 * @brief Problem 644 - Design Circular Deque
 * @aprroach Using a Doubly Linked List to implement deque. For deque, DLL makes life much simpler.
 * @date 19-07-2021
 * 
 * Runtime - 24 ms
 * Memory Usage - 16.9 MB
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

class Node
{
public:
  int data;
  Node *next, *prev;

  Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

class MyCircularDeque
{
public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  int size, currSize;
  Node *front, *rear;

  MyCircularDeque(int k) : size(k), front(nullptr), rear(nullptr), currSize(0)
  {
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value)
  {
    if (isFull())
      return false;

    Node *newNode = new Node(value);

    if (isEmpty())
      front = rear = newNode;

    newNode->prev = rear;
    rear->next = newNode;
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
    currSize++;

    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value)
  {
    if (isFull())
      return false;

    Node *newNode = new Node(value);

    if (isEmpty())
      front = rear = newNode;

    rear->next = newNode;
    newNode->prev = rear;
    rear = newNode;
    newNode->next = front;
    front->prev = newNode;
    currSize++;

    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront()
  {
    if (isEmpty())
      return false;

    if (front == rear)
      front = rear = nullptr;

    else
    {
      Node *temp = front;
      rear->next = front->next;
      front = front->next;
      front->prev = rear;
      delete temp;
    }

    currSize--;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast()
  {
    if (isEmpty())
      return false;

    if (front == rear)
      front = rear = nullptr;

    else
    {
      Node *temp = rear;
      rear = rear->prev;
      rear->next = front;
      front->prev = rear;
    }
    currSize--;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront()
  {
    if (isEmpty())
      return -1;

    return front->data;
  }

  /** Get the last item from the deque. */
  int getRear()
  {
    if (isEmpty())
      return -1;

    return rear->data;
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty()
  {
    return (front == nullptr);
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull()
  {
    return currSize == size;
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