#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdexcept>
using namespace std;

struct CNode {
  int data;
  CNode *prev, *next;
};

class queue {
  CNode *start;
  CNode *finish;
  int size;

 public:
  queue() {
    CNode *node = new CNode;
    node->prev = NULL;
    node->next = NULL;
    start = node;
    finish = node;
    size = 0;
  }
  void push(int x) {
    CNode *node = new CNode;
    node->data = x;
    node->next = NULL;
    node->prev = finish;
    finish->next = node;
    finish = node;
    if (!size)
      start = start->next;
    size++;
  }
  void pop() {
    if (size) {
      size--;
      CNode *node = start;
      start = start->prev;
      start->next = node->next;
      if (size) {
        (node->next)->prev = start;
        start = start->next;
      }
      else
        finish = start;
      delete node;
    } else
       throw logic_error("Queue is empty");
  }
  bool isEmpty() {
    return (0 == size);
  }
  int &front() {
    if (size)
      return start->data;
    else
      throw logic_error("Queue is empty");
  }
  int &back() {
    if (size)
      return finish->data;
    else
      throw logic_error("Queue is empty");
  }
};
void queueSum(int*, int, int, double*);

#endif  // _QUEUE_H_
