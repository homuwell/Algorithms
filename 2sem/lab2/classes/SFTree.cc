#include "../headers/SFTree.h"

#include <utility>
SFTree::SFTree() {
  root = nullptr;
}
SFTree::Node *SFTree::add(string str, size_t capacity) {
  Node *elem = new Node;
  elem->capacity_ = capacity;
  elem->str_ = std::move(str);
  elem->left = nullptr;
  elem->right = nullptr;
  if (root == nullptr) {
    root = elem;
  }
  return elem;
}

SFTree::Node *SFTree::get_root() {
  return root;
}

void SFTree::create_tree(size_t begin, size_t end, SymbolsList *list, Node *elem) {

  if (begin >= end) {
    return;
  }
  if (begin == end - 1) { // only two element left in group
    string tmp_str;
    tmp_str += list->get_symbol(begin);
    elem->left = add(tmp_str, list->get_frequency(begin));
    tmp_str = "";
    tmp_str += list->get_symbol(end);
    elem->right = add(tmp_str, list->get_frequency(end));
    return;
  }
  size_t start = begin;
  size_t finish = end;
  string str_finish;
  string str_start;
  str_finish += list->get_symbol(start);
  str_start += list->get_symbol(finish);
  size_t hign_sum = list->get_frequency(start);
  size_t low_sum = list->get_frequency(finish);
  while (start != finish - 1) { // find two groups with similar frequencies
    if (hign_sum > low_sum) {
      finish--;
      low_sum += list->get_frequency(finish);
      str_start += list->get_symbol(finish);
    } else {
      start++;
      hign_sum += list->get_frequency(start);
      str_finish += list->get_symbol(start);
    }
  }
  reverse(str_start.begin(), str_start.end()); // reverse right group of symbols
  elem->right = add(str_start, low_sum); // add left group to tree
  elem->left = add(str_finish, hign_sum); // add right group to tree
  create_tree(begin, start, list, elem->left); // find two new groups in left group
  create_tree(finish, end, list, elem->right); // find two new groups in right group
}

void SFTree::print(Node *elem, string str, const string &mod) {
  if (elem == root) {
    cout << +"+-" << elem->str_ << "(" << elem->capacity_ << ")" << endl;
  } else {
    cout << str + mod << elem->str_ << "(" << elem->capacity_ << ")" << endl;
  }
  str += "|  ";
  if (elem->left != nullptr) { print(elem->left, str, "L-"); }
  if (elem->right != nullptr) { print(elem->right, str, "R-"); }
}

string SFTree::get_code(char symbol) {
  string code;
  if (root->left == nullptr && root->right == nullptr) {
    code += "0";
  }
  Node *curr_elem = root;
  while (curr_elem->left != nullptr && curr_elem->right != nullptr) {
    if (curr_elem->left->str_.find(symbol) != -1) {
      code += "0";
      curr_elem = curr_elem->left;
    } else {
      code += "1";
      curr_elem = curr_elem->right;
    }
  }
  return curr_elem->str_.size() == 1 ? code : "";
}
char SFTree::get_symbol_from_code(const string &code) {
  Node *curr_elem = root;
  if (root->left != nullptr && root->right != nullptr) {
    for (char i : code) {
      if (i == '0') {
        curr_elem = curr_elem->left;
      } else {
        curr_elem = curr_elem->right;
      }
    }
  }
  return curr_elem->str_.size() == 1 ? curr_elem->str_[0] : '\n';
}

void SFTree::print_symbols_and_codes(Node *elem, string code) {
  if (elem == nullptr) {
    return;
  }
  if (elem->left == nullptr && elem->right == nullptr) {
    if (elem == root) {
      code += "1";
      cout << "Symbol: " << elem->str_ << " Code: " << code << endl;
    } else {
      cout << "Symbol: " << elem->str_ << " Code: " << code << endl;
    }
  }
  string str_left = code;
  if (elem->left) {
    str_left += "0";
    print_symbols_and_codes(elem->left, str_left);
  }
  string str_right = code;
  if (elem->right) {
    str_right += "1";
    print_symbols_and_codes(elem->right, str_right);
  }
}
SFTree::~SFTree() noexcept {
  clear(root);
}
void SFTree::clear(Node *elem) noexcept {
  if (elem == root) {
    delete root;
    return;
  }
  if (elem->left != nullptr) {
    clear(elem->left);
  }
  if (elem->right != nullptr) {
    clear(elem->right);
  }
  delete elem;
}
