#ifndef ALGORITHMS_MAP_H
#define ALGORITHMS_MAP_H

#include "List.h"

using namespace std;

template <class T, class T1>
class Map {
 private:
  struct Node {
    T key;
    T1 value;
    Node *parent;
    Node *left;
    Node *right;
    bool color;
  };
  Node *root;
  Node *nil;

  void Left_Rotate(Node *elem);

  void Right_Rotate(Node *elem);

  void RB_Insert_Fixup(Node *elem);

  void RB_Transplant(Node *org_elem, Node *swap_elem);

  Node *Tree_Minimum(Node *elem) const;

  void Fill(Node *elem, List<T> *keys) const;

  void Fill(Node *elem, List<T1> *values) const;

  void RB_Delete_Fixup(Node *elem);

  void printElem(Node *elem, string str = "", string mod = " ") const;

 public:
  Map();

  ~Map();

  void insert(const T key, const T1 value);

  Node *find(const T key) const;

  List<T> *get_keys() const;

  bool check(List<T> *checking_list, List<T> *corr_list) const;

  bool check(List<T1> *checking_list, List<T1> *corr_list) const;

  List<T1> *get_values() const;

  void remove(const T key);

  bool isEmpty() const;

  void print() const;

  void clear();
};

#include "../classes/map.cpp"

#endif //ALGORITHMS_MAP_H
