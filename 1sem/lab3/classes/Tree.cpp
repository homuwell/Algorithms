#include "../headers/Tree.h"
Tree::Tree() {
  head = nullptr;
};
bool Tree::contains(int value) {
  Node *tmp_ptr = head;
  while (tmp_ptr != nullptr && tmp_ptr->key != value) {
    if (tmp_ptr->key > value) {
      tmp_ptr = tmp_ptr->left;
    } else {
      tmp_ptr = tmp_ptr->right;
    }
  }
  return tmp_ptr != nullptr;
};
void Tree::insert(int value) {
  if (head == nullptr) {
    Node *elem = new Node;
    elem->left = nullptr;
    elem->right = nullptr;
    elem->key = value;
    head = elem;
  } else {
    Node *tmp_ptr = head;
    while (tmp_ptr != nullptr && tmp_ptr->key != value) {
      if (tmp_ptr->key < value && tmp_ptr->right != nullptr) {
        tmp_ptr = tmp_ptr->right;
      } else if (tmp_ptr->key > value && tmp_ptr->left != nullptr) {
        tmp_ptr = tmp_ptr->left;
      } else {
        Node *elem = new Node;
        elem->key = value;
        elem->right = nullptr;
        elem->left = nullptr;
        if (tmp_ptr->key < value) {
          tmp_ptr->right = elem;
          tmp_ptr = elem;
        } else {
          tmp_ptr->left = elem;
          tmp_ptr = elem;
        }
      }
    }
  }
}
void Tree::remove(int value) {
  if (!contains(value)) {
    throw out_of_range("Tree doesnt contain deleted element");
  }
  if (!head) {
    throw out_of_range("Three is empty");
  }
  Node *del_element = head;
  Node *del_parent = head;
  while (del_element->key != value) {
    if (del_element->key > value) {
      del_parent = del_element;
      del_element = del_element->left;
    } else {
      del_parent = del_element;
      del_element = del_element->right;
    }
  }
  if (del_element->left == nullptr && del_element->right == nullptr) {
    del_parent->left == del_element ? del_parent->left = nullptr : del_parent->right = nullptr;
    delete del_element;
  } else if (del_element->left != nullptr && del_element->right != nullptr) {
    if (del_element->left) {
      Node *tmp_ptr = del_element->left;
      Node *parent = del_element;
      while (tmp_ptr->right != nullptr) {
        parent = tmp_ptr;
        tmp_ptr = tmp_ptr->right;
      }
      del_element->key = tmp_ptr->key;
      parent->left = nullptr;
      delete tmp_ptr;
    } else {
      Node *tmp_ptr = del_element->right;
      Node *parent = del_element;
      while (tmp_ptr->left != nullptr) {
        parent = tmp_ptr;
        tmp_ptr = tmp_ptr->left;
      }
      del_element->key = tmp_ptr->key;
      parent->right = nullptr;
      delete tmp_ptr;
    }
  } else {
    if (del_element->right) {
      del_parent->right == del_element ? del_parent->right = del_element->right : del_parent->left = del_element->right;
      delete del_element;
    } else {
      del_parent->right == del_element ? del_parent->right = del_element->left : del_parent->left = del_element->left;
      delete del_element;
    }
  }
}
void Tree::BFT_Iterator::push(Node *value) {
  queue *elem = new queue;
  elem->data = value;
  elem->next = nullptr;
  if (headq == nullptr) {
    headq = elem;
    headq->next = nullptr;
    last = elem;
  } else {
    last->next = elem;
    last = last->next;
  }
}
void Tree::BFT_Iterator::pop() {
  queue *tmp_ptr = headq->next;
  headq->next = nullptr;
  delete headq;
  headq = tmp_ptr;
}
int Tree::BFT_Iterator::next() {
  curr = headq->data;
  int rmbr_elem = headq->data->key;
  pop();
  if (curr->right) {
    push(curr->left);
  }
  if (curr->right) {
    push(curr->right);
  }
  return rmbr_elem;
}
Iterator *Tree::create_BFT_Iterator(Node *elm) {
  return new BFT_Iterator(elm);
}
bool Tree::BFT_Iterator::has_next() {
  return headq != nullptr;
}
void Tree::DFT_Iterator::push(Node *value) {
  stack *elem = new stack;
  elem->data = value;
  if (top == nullptr) {
    top = elem;
    top->prev = nullptr;
  } else {
    elem->prev = top;
    top = elem;
  }
}
void Tree::DFT_Iterator::pop() {
  stack *tmp_ptr = top;
  Node *rmbr_data = top->data;
  top = tmp_ptr->prev;
  tmp_ptr->prev = nullptr;
  delete tmp_ptr;
}
bool Tree::DFT_Iterator::has_next() {
  return top != nullptr;
}
int Tree::DFT_Iterator::next() {
  int rmbr_elem;
  if (!has_next()) {
    throw out_of_range("Iterator out of range");
  }
  curr = top->data;
  rmbr_elem = top->data->key;
  pop();
  if (curr->right) {
    push(curr->right);
  }
  if (curr->left) {
    push(curr->left);
  }
  return rmbr_elem;
}
Iterator *Tree::create_DFT_Iterator(Node *elm) {
  return new DFT_Iterator(elm);
}
void Tree::print(Node *elem, string str, string mod) {
  if (elem == head) {
    cout << +"+-" << elem->key << endl;
  } else {
    cout << str + mod << elem->key << endl;
  }
  str += "|  ";
  if (elem->left) { print(elem->left, str, "L-"); }
  if (elem->right) { print(elem->right, str, "R-"); };
}

void Tree::del(Node *&elem) {
  if (elem == nullptr) {
    return;
  }
  if (elem->left) {
    del(elem->left);
  }
  if (elem->right) {
    del(elem->right);
  }
  delete elem;
}
Tree::~Tree() {
  del(head);
}
