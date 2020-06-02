#include "../headers/map.h"
#include "../headers/constants.h"

using namespace constants;

template <class T, class T1>
Map<T, T1>::Map() {
  nil = new Node;
  nil->parent = nullptr;
  nil->color = BLACK;
  nil->left = nullptr;
  nil->right = nullptr;
  root = nil;
  root->parent = nil;
}

template <class T, class T1>
void Map<T, T1>::insert(const T key, const T1 value) {
  if (find(key) != nullptr) {
    throw invalid_argument("This key already exist in array");
  }
  Node *elem = new Node;
  elem->key = key;
  elem->value = value;
  Node *elem_parent = nil;
  Node *curr_node = root;
  while (curr_node != nil) {
    elem_parent = curr_node;
    if (elem->key < curr_node->key) {
      curr_node = curr_node->left;
    } else {
      curr_node = curr_node->right;
    }
  }
  elem->parent = elem_parent;
  if (elem_parent == nil) {
    root = elem;
  } else if (elem->key < elem_parent->key) {
    elem_parent->left = elem;
  } else {
    elem_parent->right = elem;
  }
  elem->left = nil;
  elem->right = nil;
  elem->color = RED;
  RB_Insert_Fixup(elem);
}

template <class T, class T1>
void Map<T, T1>::Left_Rotate(Node *elem) {
  Node *r_elem = elem->right;
  elem->right = r_elem->left;
  if (r_elem->left != nil) {
    r_elem->left->parent = elem;
  }
  r_elem->parent = elem->parent;
  if (elem->parent == nil) {
    root = r_elem;
  } else if (elem == elem->parent->left) {
    elem->parent->left = r_elem;
  } else {
    elem->parent->right = r_elem;
  }
  r_elem->left = elem;
  elem->parent = r_elem;
}

template <class T, class T1>
void Map<T, T1>::Right_Rotate(Node *elem) {
  Node *l_elem = elem->left;
  elem->left = l_elem->right;
  if (l_elem->right != nil) {
    l_elem->right->parent = elem;
  }
  l_elem->parent = elem->parent;
  if (elem->parent == nil) {
    root = l_elem;
  } else if (elem == elem->parent->right) {
    elem->parent->right = l_elem;
  } else {
    elem->parent->left = l_elem;
  }
  l_elem->right = elem;
  elem->parent = l_elem;
}

template <class T, class T1>
void Map<T, T1>::RB_Insert_Fixup(Node *elem) {
  Node *uncle = nullptr;
  while (elem->parent->color == RED) {
    if (elem->parent == elem->parent->parent->left) {
      uncle = elem->parent->parent->right;
      if (uncle->color == RED) {
        elem->parent->color = BLACK;
        uncle->color = BLACK;
        elem->parent->parent->color = RED;
        elem = elem->parent->parent;
      } else {
        if (elem == elem->parent->right) {
          elem = elem->parent;
          Left_Rotate(elem);
        }
        elem->parent->color = BLACK;
        elem->parent->parent->color = RED;
        Right_Rotate(elem->parent->parent);
      }
    } else {
      uncle = elem->parent->parent->left;
      if (uncle->color == RED) {
        elem->parent->color = BLACK;
        uncle->color = BLACK;
        elem->parent->parent->color = RED;
        elem = elem->parent->parent;
      } else {
        if (elem == elem->parent->left) {
          elem = elem->parent;
          Right_Rotate(elem);
        }
        elem->parent->color = BLACK;
        elem->parent->parent->color = RED;
        Left_Rotate(elem->parent->parent);
      }
    }
  }
  root->color = BLACK;
}

template <class T, class T1>
typename Map<T, T1>::Node *Map<T, T1>::find(const T key) const {
  Node *elem = root;
  while (elem != nil) {
    if (elem->key == key) {
      break;
    }
    if (key < elem->key) {
      elem = elem->left;
    } else {
      elem = elem->right;
    }
  }
  if (elem != nil) {
    return elem;
  } else {
    return nullptr;
  }
}

template <class T, class T1>
void Map<T, T1>::RB_Transplant(Node *org_elem, Node *swap_elem) {
  if (org_elem->parent == nil) {
    root = swap_elem;
  } else if (org_elem == org_elem->parent->left) {
    org_elem->parent->left = swap_elem;
  } else {
    org_elem->parent->right = swap_elem;
  }
  swap_elem->parent = org_elem->parent;
}

template <class T, class T1>
typename Map<T, T1>::Node *Map<T, T1>::Tree_Minimum(Node *elem) const {
  Node *curr_elem = elem;
  while (curr_elem->left != nil) {
    curr_elem = curr_elem->left;
  }
  return curr_elem;
}

template <class T, class T1>
void Map<T, T1>::remove(const T key) {
  Node *elem = find(key);
  if (elem == nullptr) {
    throw invalid_argument("Key does not exist in array");
  }
  Node *child_elem = nullptr;
  Node *min_child_elem = elem;
  bool org_color = min_child_elem->color;
  if (elem->left == nil) {
    child_elem = elem->right;
    RB_Transplant(elem, elem->right);
  } else if (elem->right == nil) {
    child_elem = elem->left;
    RB_Transplant(elem, elem->left);
  } else {
    min_child_elem = Tree_Minimum(elem->right);
    org_color = min_child_elem->color;
    child_elem = min_child_elem->right;
    if (min_child_elem->parent == elem) {
      child_elem->parent = min_child_elem;
    } else {
      RB_Transplant(min_child_elem, min_child_elem->right);
      min_child_elem->right = elem->right;
      min_child_elem->right->parent = min_child_elem;
    }
    RB_Transplant(elem, min_child_elem);
    min_child_elem->left = elem->left;
    min_child_elem->left->parent = min_child_elem;
    min_child_elem->color = elem->color;
  }
  if (org_color == BLACK) {
    RB_Delete_Fixup(child_elem);
  }
}

template <class T, class T1>
void Map<T, T1>::RB_Delete_Fixup(Node *elem) {
  Node *brother = nullptr;
  while (elem != root && elem->color == BLACK) {
    if (elem == elem->parent->left) {
      brother = elem->parent->right;
      if (brother->color == RED) {
        brother->color = BLACK;
        elem->parent->color = RED;
        Left_Rotate(elem->parent);
        brother = elem->parent->right;
      }
      if (brother->left->color == BLACK && brother->right->color == BLACK) {
        brother->color = RED;
        elem = elem->parent;
      } else {
        if (brother->right->color == BLACK) {

          brother->left->color = BLACK;
          brother->color = RED;
          Right_Rotate(brother);
          brother = elem->parent->right;

        }
        brother->color = elem->parent->color;
        elem->parent->color = BLACK;
        brother->right->color = BLACK;
        Left_Rotate(elem->parent);
        elem = root;
      }
    } else {
      brother = elem->parent->left;
      if (brother->color == RED) {
        brother->color = BLACK;
        elem->parent->color = RED;
        Right_Rotate(elem->parent);
        brother = elem->parent->left;
      }
      if (brother->right->color == BLACK && brother->left->color == BLACK) {
        brother->color = RED;
        elem = elem->parent;
      } else {
        if (brother->left->color == BLACK) {
          brother->right->color = BLACK;
          brother->color = RED;
          Left_Rotate(brother);
          brother = elem->parent->left;

        }
        brother->color = elem->parent->color;
        elem->parent->color = BLACK;
        brother->left->color = BLACK;
        Right_Rotate(elem->parent);
        elem = root;
      }
    }
  }
  elem->color = BLACK;
}

template <class T, class T1>
Map<T, T1>::~Map() {
  while (root != nil && root != nullptr) {
    remove(root->key);
  }
  nil->parent = nullptr;
  delete nil;

}

template <class T, class T1>
void Map<T, T1>::Fill(Node *elem, List<T> *keys) const {
  if (elem != nil) {
    Fill(elem->left, keys);
    keys->push_back(elem->key);
    Fill(elem->right, keys);
  }

}

template <class T, class T1>
void Map<T, T1>::Fill(Node *elem, List<T1> *values) const {
  if (elem != nil) {
    Fill(elem->left, values);
    values->push_back(elem->value);
    Fill(elem->right, values);
  }

}

template <class T, class T1>
List<T> *Map<T, T1>::get_keys() const {
  if (root == nil) {
    throw out_of_range("Array is empty");
  }
  List<T> *keys = new List<T>;
  Fill(root, keys);
  return keys;
}

template <class T, class T1>
List<T1> *Map<T, T1>::get_values() const {
  if (root == nil) {
    throw out_of_range("Array is empty");
  }
  List<T1> *values = new List<T1>;
  Fill(root, values);
  return values;
}

template <class T, class T1>
void Map<T, T1>::printElem(Node *elem, string str, string mod) const {
  if (elem == root) {
    cout << +"+-" << elem->key << "(" << elem->value << ")" << endl;
  } else {
    cout << str + mod << elem->key << "(" << elem->value << ")" << endl;
  }
  str += "|  ";
  if (elem->left != nil) { printElem(elem->left, str, "L-"); }
  if (elem->right != nil) { printElem(elem->right, str, "R-"); };
}

template <class T, class T1>
void Map<T, T1>::print() const {
  if (root == nil) {
    throw out_of_range("Array is empty");
  }
  printElem(root);
}

template <class T, class T1>
bool Map<T, T1>::check(List<T> *checking_list, List<T> *corr_list) const {
  if (checking_list->isEmpty() || corr_list->isEmpty()) {
    throw invalid_argument("At least one of the List is Empty");
  }
  bool flag = true;
  for (int i = 0; i < checking_list->get_size(); i++) {
    if (checking_list->at(i) != corr_list->at(i)) {
      flag = false;
      break;
    }
  }
  return flag;
}

template <class T, class T1>
bool Map<T, T1>::check(List<T1> *checking_list, List<T1> *corr_list) const {
  if (checking_list->isEmpty() || corr_list->isEmpty()) {
    throw invalid_argument("At least one of the List is Empty");
  }
  bool flag = true;
  for (int i = 0; i < checking_list->get_size(); i++) {
    if (checking_list->at(i) != corr_list->at(i)) {
      flag = false;
      break;
    }
  }
  return flag;
}

template <class T, class T1>
bool Map<T, T1>::isEmpty() const {
  return root == nil;
}

template <class T, class T1>
void Map<T, T1>::clear() {
  while (root != nil) {
    remove(root->key);
  }
  root = nil;
}
