//
// Created by homuwell on 2020-05-31.
//

#ifndef ALGORITHMS_2SEM_COURSE_WORK_HEADERS_QUEUE_H_
#define ALGORITHMS_2SEM_COURSE_WORK_HEADERS_QUEUE_H_
template <class T>
class Queue {
  struct Node {
    T data_;
    Node *next_;
  };
  Node *head_;
  Node *last_;
 public:
  T front();
  bool empty();
  Queue();
  ~Queue();
  void pop();
  void push(T data);
};

template <class T>
Queue<T>::Queue() {
  head_ = nullptr;
  last_ = nullptr;
}
template <class T>
Queue<T>::~Queue<T>() {
  if (head_ == nullptr) {
    return;
  } else if (head_->next_ == nullptr) {
    delete head_;
  } else {
    while (head_->next_ != nullptr) {
      pop();
    }
    delete head_;
  }
}

template <class T>
void Queue<T>::pop() {
  if (head_ == nullptr) {
    return;
  }
  if (head_->next_ == nullptr) {
    delete head_;
    head_ = nullptr;
    last_ = nullptr;
  } else {
    Node *tmp_ptr = head_->next_;
    delete head_;
    head_ = tmp_ptr;
  }
}

template <class T>
bool Queue<T>::empty() {
  return head_ == nullptr;
}

template <class T>
T Queue<T>::front() {
  return head_->data_;
}

template <class T>
void Queue<T>::push(T data) {
  auto elem = new Node;
  elem->data_ = data;
  elem->next_ = nullptr;
  if (head_ == nullptr) {
    head_ = elem;
    last_ = elem;
  } else {
    last_->next_ = elem;
    last_ = elem;
  }
}

#endif //ALGORITHMS_2SEM_COURSE_WORK_HEADERS_QUEUE_H_
