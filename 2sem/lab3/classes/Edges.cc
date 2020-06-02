#include "../headers/Graph.h"

#include <utility>

Graph::vertex_::Edges::Edges() {
  head_ = nullptr;
  last_ = nullptr;
}

void Graph::vertex_::Edges::push_back(size_t weight, vertex_ *city) {
  auto *elem = new edge_;
  elem->city_ = city;
  elem->weight_ = weight;
  elem->next_ = nullptr;
  if (head_ == nullptr) {
    head_ = elem;
    last_ = elem;
  } else {
    last_->next_ = elem;
    last_ = elem;
  }
}

void Graph::vertex_::Edges::pop_front() {
  if (head_ == nullptr) {
    return;
  }
  if (head_->next_ != nullptr) {
    auto next_elem = head_->next_;
    head_->next_ = nullptr;
    delete head_;
    head_ = next_elem;
  } else {
    head_->next_ = nullptr;
    delete head_;
    head_ = nullptr;
    last_ = nullptr;
  }
}
void Graph::vertex_::Edges::clear() noexcept {
  if (head_ == nullptr) {
    return;
  } else if (head_->next_ == nullptr) {
    pop_front();
  } else {
    while (head_->next_ != nullptr) {
      pop_front();
    }
    pop_front();
  }
}
Graph::vertex_::Edges::~Edges() noexcept {
  clear();
}
//
// Created by homuwell on 2020-05-28.
//

