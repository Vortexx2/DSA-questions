/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 622 - Design Circular Queue
 * @approach Using a doubly linked list to store the queue. Can be implemented using singly linked list.
 * @date 19-07-2021
 * 
 * Runtime - 28 ms
 * Memory Usage - 17.1 MB
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
  Node *prev;
  Node *next;

  Node(int x) : data(x), prev(nullptr), next(nullptr)
  {
  }
};

class MyCircularQueue
{
public:
  int size;
  int currSize;
  Node *front, *rear;
  MyCircularQueue(int k) : size(k), currSize(0) {}

  bool enQueue(int value)
  {
    if (isFull())
      return false;

    Node *newNode = new Node(value);
    newNode->next = front;

    if (isEmpty())
    {
      front = newNode;
      rear = front;
    }

    else
    {
      rear->next = newNode;
      rear = newNode;
    }
    currSize++;
    return true;
  }

  bool deQueue()
  {
    if (isEmpty())
      return false;

    if (front == rear)
    {
      delete front;
      front = rear = nullptr;
      currSize--;
      return true;
    }

    Node *temp = front;
    front = front->next;
    delete temp;
    rear->next = front;

    currSize--;
    return true;
  }

  int Front()
  {
    if (isEmpty())
      return -1;

    return front->data;
  }

  int Rear()
  {
    if (isEmpty())
      return -1;

    return rear->data;
  }

  bool isEmpty()
  {
    return currSize == 0;
  }

  bool isFull()
  {
    return currSize == size;
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