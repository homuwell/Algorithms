#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H
using namespace std;

template <class K>
class List {
  struct NodeL {
    K data;
    NodeL *next;
  };
  NodeL *last;
  NodeL *head;
 public:
  List();

  ~List();

  void push_back(K value);

  void clear();

  void pop_back();

  int get_size() const;

  bool isEmpty() const;

  K at(size_t id) const;
};

#include "../classes/List.cpp"

#endif //ALGORITHMS_LIST_H
