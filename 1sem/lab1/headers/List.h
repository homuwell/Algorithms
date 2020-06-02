
#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H
using namespace std;
#include <iostream>
class List {
 public:
  struct Node {
    int info;
    Node *next;
  };
  Node *head;
  Node *last;
  List(int num = 5);
  ~List();
  void push_back(int num);
  void push_front(int num);
  void pop_back();
  void pop_front();
  void insert(int num, size_t id);
  int at(size_t id);
  void remove(size_t id);
  int get_size();
  void print_to_console();
  void clear();
  void set(size_t id, int num);
  bool isEmpty();
  size_t find_first(List &name);

};
#endif //ALGORITHMS_LIST_H
