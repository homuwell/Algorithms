using namespace std;
#include <iostream>
#include "Iterator.h"
class Tree {
 public:
  struct Node {
    int key;
    Node *left;
    Node *right;
  };
  Node *head;
  void print(Node *elem, string str, string mod);
  Tree();
  ~Tree();
  void del(Node *&elem);
  void insert(int value);
  bool contains(int value);
  void remove(int value);
  Iterator *create_BFT_Iterator(Node *elm);
  Iterator *create_DFT_Iterator(Node *elm);
  class BFT_Iterator : public Iterator {
   public:
    BFT_Iterator(Node *root) {
      queue *elem = new queue;
      headq = elem;
      elem->data = root;
      elem->next = nullptr;
      last = elem;
      curr = root;
    };
    struct queue {
      Node *data;
      queue *next;

    };
    queue *headq;
    queue *last;
    void push(Node *value);
    void pop();
    Node *curr;
    int next() override;
    bool has_next() override;
  };
  class DFT_Iterator : public Iterator {
   public:
    Node *curr;
    DFT_Iterator(Node *root) {
      stack *elem = new stack;
      elem->data = root;
      elem->prev = nullptr;
      top = elem;
    };
    struct stack {
      Node *data;
      stack *prev;
    };
    stack *top;
    void push(Node *value);
    void pop();
    int next() override;
    bool has_next() override;
  };

};
#ifndef ALGORITHMS_TREE_H
#define ALGORITHMS_TREE_H
#endif //ALGORITHMS_TREE_H
