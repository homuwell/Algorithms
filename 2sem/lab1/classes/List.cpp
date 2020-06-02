
#include "../headers/List.h"

template <class K>
List<K>::List() {
  head = nullptr;
  last = nullptr;

}

template <class K>
void List<K>::push_back(K value) {
  NodeL *elem = new NodeL;
  elem->data = value;
  elem->next = nullptr;
  if (head == nullptr) {
    head = elem;
    last = elem;
  } else {
    last->next = elem;
    last = elem;
  }
}

template <class K>
void List<K>::clear() {
  while (head != nullptr) {
    pop_back();
  }
}

template <class K>
void List<K>::pop_back() {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  NodeL *tmp_ptr = head;
  if (tmp_ptr->next == nullptr) {
    delete tmp_ptr;
    head = nullptr;
    last = nullptr;
  } else {
    while (tmp_ptr->next != last) {
      tmp_ptr = tmp_ptr->next;
    }
    tmp_ptr->next = nullptr;
    delete last;
    last = tmp_ptr;
  }
}

template <class K>
int List<K>::get_size() const {
  if (isEmpty()) {
    return 0;
  }
  int i = 1;
  NodeL *tmp_ptr = head;
  while (tmp_ptr->next != nullptr) {
    tmp_ptr = tmp_ptr->next;
    i++;
  }
  return i;
};

template <class K>
K List<K>::at(size_t id) const {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  int i = 0;
  NodeL *tmp_ptr = head;
  while (i < id) {
    tmp_ptr = tmp_ptr->next;
    i++;
  }
  return tmp_ptr->data;
}

template <class K>
bool List<K>::isEmpty() const {
  return head == nullptr;
}

template <class K>
List<K>::~List() {
  clear();
}



