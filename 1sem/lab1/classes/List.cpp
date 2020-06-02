#include "../headers/List.h"
List::List(int num) {
  head = nullptr;
  last = nullptr;

}
void List::push_back(int num) {
  Node *elem = new Node;
  elem->info = num;
  if (head == nullptr) {
    head = elem;
    last = elem;
    elem->next = nullptr;
  } else {
    last->next = elem;
    last = elem;
  }
}
void List::push_front(int num) {
  Node *elem = new Node;
  elem->info = num;
  if (head == nullptr) {
    head = elem;
    last = elem;
    elem->next = nullptr;
  } else {
    elem->next = head;
    head = elem;
  }
}
void List::pop_back() {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  Node *tmp_ptr = head;
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
void List::pop_front() {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    last = nullptr;
  } else {
    Node *tmp_ptr = head->next;
    delete head;
    head = tmp_ptr;
  }
}
void List::insert(int num, size_t id) {
  if (id > get_size()) {
    throw out_of_range("Error, id number is larger than size of list");
  }
  Node *elem = new Node;
  elem->info = num;
  if (id == 0) {
    elem->next = head;
    head = elem;
  } else {
    int i = 0;
    Node *tmp_ptr = head;
    while (i < id - 1) {
      tmp_ptr = tmp_ptr->next;
      i++;
    }
    elem->next = tmp_ptr->next;
    tmp_ptr->next = elem;
  }
}
int List::at(size_t id) {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  if (id > get_size()) {
    throw out_of_range("Error, id number is larger than size of list");
  }
  int i = 0;
  Node *tmp_ptr = head;
  while (i < id) {
    tmp_ptr = tmp_ptr->next;
    i++;
  }
  return tmp_ptr->info;
}
void List::remove(size_t id) {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  if (id > get_size()) {
    throw out_of_range("Error, id number is larger than size of list");
  }
  if (id == 0 && head->next == nullptr) {
    delete head;
    head = nullptr;
    last = nullptr;
  } else {
    int i = 0;
    Node *tmp_ptr = head;
    Node *tmp_ptr_prev = head;
    while (i < id) {
      tmp_ptr_prev = tmp_ptr;
      tmp_ptr = tmp_ptr->next;
      i++;
    }
    if (tmp_ptr == last) {
      tmp_ptr_prev->next = nullptr;
      last = tmp_ptr_prev;
      delete tmp_ptr;
    } else {
      if (tmp_ptr == head) { tmp_ptr = head->next; }
      tmp_ptr_prev->next = tmp_ptr->next;
      tmp_ptr->next = nullptr;
      delete tmp_ptr;
    }
  }
}
int List::get_size() {
  if (isEmpty()) {
    return 0;
  }
  int i = 1;
  Node *tmp_ptr = head;
  while (tmp_ptr->next != nullptr) {
    tmp_ptr = tmp_ptr->next;
    i++;
  }
  return i;
};

void List::print_to_console() {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  Node *tmp_ptr = head;
  cout << tmp_ptr->info << " -> ";
  while (tmp_ptr->next != nullptr) {
    tmp_ptr = tmp_ptr->next;
  }
  if (head->next != nullptr) {
    cout << tmp_ptr->info;
    cout << "X";
  } else {
    cout << "X";
  }

}
void List::clear() {
  if (head != nullptr) {
    while (head != nullptr) {
      pop_back();
    }
  }
}
void List::set(size_t id, int num) {
  if (head == nullptr) {
    throw out_of_range("Error, the List is empty");
  }
  if (id > get_size()) {
    throw out_of_range("Error, id number is larger than size of list");
  }
  int i = 0;
  Node *tmp_ptr = head;
  while (i < id) {
    tmp_ptr = tmp_ptr->next;
    i++;
  }
  tmp_ptr->info = num;
}
bool List::isEmpty() {
  return head == nullptr;
}
size_t List::find_first(List &name) {
  if (head == nullptr || name.head == nullptr) {
    throw out_of_range("Error, some of the List is Empty");
  }
  bool flag;
  int counter;
  counter = 0;
  Node *tmp_ptr = head;
  Node *tmp_ptr_name = name.head;
  Node *rmbr_ptr = tmp_ptr;
  if (name.get_size() > get_size()) {
    return 0;
  }
  while (tmp_ptr != nullptr) {
    flag = true;
    rmbr_ptr = tmp_ptr;
    while (tmp_ptr_name != nullptr) {
      if (tmp_ptr_name->info != tmp_ptr->info) {
        flag = false;
      }
      tmp_ptr = tmp_ptr->next;
      tmp_ptr_name = tmp_ptr_name->next;
      if (tmp_ptr == nullptr && tmp_ptr_name != nullptr) { break; }

    }
    if (flag) {
      return counter;
    }
    counter++;
    tmp_ptr_name = name.head;
    tmp_ptr = rmbr_ptr->next;
  }
}
List::~List() {
  clear();
}

