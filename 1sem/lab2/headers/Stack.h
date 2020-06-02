using namespace std;
#include <iostream>
template <class T>
class Stack {
 public:
  struct Node {
    T data;
    Node *prev;
  };
  Node *top;
  Stack();
  void push(T value);
  T pop();
  T peek();
  size_t get_size();
  bool empty();
  ~Stack();
};

#include "../classes/Stack.cpp"
#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#endif //ALGORITHMS_STACK_H
