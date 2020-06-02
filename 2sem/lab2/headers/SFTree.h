#include <string>
#include <iostream>
#include <algorithm>
using std::string, std::reverse;
#include "../headers/SymbolsList.h"
#include "../../lab1/headers/map.h"
#ifndef ALGORITHMS_2SEM_LAB2_HEADERS_SFTREE_H_
#define ALGORITHMS_2SEM_LAB2_HEADERS_SFTREE_H_
class SFTree {
 private:
  struct Node {
    string str_;
    size_t capacity_;
    Node *left;
    Node *right;
  };
  Node *root;
 public:
  SFTree();
  ~SFTree() noexcept;
  void clear(Node *elem) noexcept;
  Node *get_root();
  Node *add(string str, size_t capacity);
  void create_tree(size_t begin, size_t end, SymbolsList *list, Node *elem);
  void print(Node *elem, string str = "", const string &mod = "");
  string get_code(char symbol);
  char get_symbol_from_code(const string &code);
  void print_symbols_and_codes(Node *elem, string code);
};
#endif //ALGORITHMS_2SEM_LAB2_HEADERS_SFTREE_H_
