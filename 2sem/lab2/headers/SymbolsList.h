#include <cstddef>
#include <string>
using namespace std;
#ifndef ALGORITHMS_2SEM_LAB2_HEADERS_SYMBOLSLIST_H_
#define ALGORITHMS_2SEM_LAB2_HEADERS_SYMBOLSLIST_H_
class SymbolsList {
 private:
  struct Node {
    size_t frequency_;
    char symbol_;
    Node *next;
    Node *prev;
  };
  Node *head;
  Node *last;
 public:
  SymbolsList();
  ~SymbolsList() noexcept;
  void push_back(char symbol);
  void pop_back() noexcept;
  void clear() noexcept;
  size_t get_size();
  bool update_frequency(char symbol);
  bool is_empty();
  Node *MergeSort(Node *elem);
  Node *merge_sorted_lists(Node *first, Node *second);
  Node *split_list(Node *front);
  void sort();
  void reverse();
  Node *find(size_t);
  size_t get_frequency(size_t id);
  char get_symbol(size_t id);
  void fix_last();
};
#endif //ALGORITHMS_2SEM_LAB2_HEADERS_SYMBOLSLIST_H_
