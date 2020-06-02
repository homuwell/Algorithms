
template <class T>
Stack<T>::Stack() {
  top = nullptr;
}
template <class T>
void Stack<T>::push(T value) {
  Node *elem = new Node;
  elem->data = value;
  if (top == nullptr) {
    top = elem;
    top->prev = nullptr;
  } else {
    elem->prev = top;
    top = elem;
  }

}
template <class T>
T Stack<T>::pop() {
  if (top == nullptr) {
    throw invalid_argument("Stack is Empty");
  }
  Node *tmp_ptr = top;
  T rmbr_data = top->data;
  top = tmp_ptr->prev;
  tmp_ptr->prev = nullptr;
  delete tmp_ptr;
  return rmbr_data;
}
template <class T>
T Stack<T>::peek() {
  if (top == nullptr) {
    throw out_of_range("Stack is Empty");
  }
  return top->data;
}
template <class T>
size_t Stack<T>::get_size() {
  if (top == nullptr) {
    return 0;
  }
  int i = 0;
  Node *rmbr_ptr = top;
  while (top != nullptr) {
    top = top->prev;
    i++;
  }
  top = rmbr_ptr;
  return i;
}
template <class T>
Stack<T>::~Stack() {
  while (top != nullptr) {
    pop();
  }
  top = nullptr;
}

template <class T>
bool Stack<T>::empty() {
  return top == nullptr;

}