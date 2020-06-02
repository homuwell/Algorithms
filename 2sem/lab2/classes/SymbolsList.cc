#include "../headers/SymbolsList.h"
using namespace std;
SymbolsList::SymbolsList() {
  head = nullptr;
  last = nullptr;
}

void SymbolsList::push_back(char symbol) {
  Node *elem = new Node;
  elem->symbol_ = symbol;
  elem->frequency_ = 1;
  if (head == nullptr) {
    elem->prev = nullptr;
    elem->next = nullptr;
    head = elem;
    last = elem;
  } else {
    last->next = elem;
    elem->prev = last;
    elem->next = nullptr;
    last = elem;
  }
}

void SymbolsList::pop_back() noexcept {
  if (head == nullptr) {
    return;
  }
  if (head->prev == nullptr) {
    delete head;
    head = nullptr;
    last = nullptr;
  } else {
    Node *del_elem = last;
    Node *prev_del = last->prev;
    prev_del->next = nullptr;
    del_elem->prev = nullptr;
    last = prev_del;
    delete del_elem;
  }
}

void SymbolsList::clear() noexcept {
  while (head->next != nullptr) {
    pop_back();
  }
  delete head;
  head = nullptr;
  last = nullptr;
}

SymbolsList::~SymbolsList() noexcept {
  clear();
}
bool SymbolsList::is_empty() {
  return head == nullptr;
}
size_t SymbolsList::get_size() {
  if (is_empty()) {
    return 0;
  } else {
    size_t i = 1;
    Node *tmp_elem = head;
    while (tmp_elem->next != nullptr) {
      tmp_elem = tmp_elem->next;
      i++;
    }
    return i;
  }
}
bool SymbolsList::update_frequency(char symbol) {
  Node *curr_elem = head;
  while (curr_elem != nullptr) {
    if (curr_elem->symbol_ == symbol) {
      break;
    }
    curr_elem = curr_elem->next;
  }
  if (curr_elem == nullptr) { // if symbol not in list we create new element and set frequency to 1
    push_back(symbol);
    return false;
  } else { // if symbol exist in list we just update frequency
    curr_elem->frequency_ += 1;
    return true;
  }
}

SymbolsList::Node *SymbolsList::merge_sorted_lists(Node *first, Node *second) {
  if (first == nullptr) {
    return second;
  }
  if (second == nullptr) {
    return first;
  }
  if (first->frequency_ < second->frequency_) {
    first->next = merge_sorted_lists(first->next, second);
    first->next->prev = first;
    first->prev = nullptr;
    return first;
  } else {
    second->next = merge_sorted_lists(first, second->next);
    second->next->prev = second;
    second->prev = nullptr;
    return second;
  }
}

SymbolsList::Node *SymbolsList::split_list(Node *front) {
  Node *slow = front;
  Node *fast = front;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  Node *temp = slow->next;
  slow->next = nullptr;
  return temp;
}

SymbolsList::Node *SymbolsList::MergeSort(Node *elem) {
  if (elem == nullptr || elem->next == nullptr) {
    return elem;
  }
  Node *second = split_list(elem);
  elem = MergeSort(elem);
  second = MergeSort(second);
  return merge_sorted_lists(elem, second);
}

void SymbolsList::sort() {
  head = MergeSort(head);
  fix_last();
  reverse();
}

void SymbolsList::reverse() {
  Node *temp = nullptr;
  Node *current = head;
  while (current != nullptr) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if (temp != nullptr) {
    head = temp->prev;
  }
  fix_last();
}

size_t SymbolsList::get_frequency(size_t id) {
  return find(id)->frequency_;
}
SymbolsList::Node *SymbolsList::find(size_t id) {
  Node *curr_elem = head;
  size_t num = 0;
  while (num < id) {
    num += 1;
    curr_elem = curr_elem->next;
  }
  return curr_elem;
}
char SymbolsList::get_symbol(size_t id) {
  return find(id)->symbol_;
}

void SymbolsList::fix_last() {
  Node *tmp_ptr = head;
  while (tmp_ptr->next != nullptr) {
    tmp_ptr = tmp_ptr->next;
  }
  last = tmp_ptr;
}