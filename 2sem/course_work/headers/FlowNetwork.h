#include <string>
#include <fstream>
#include <utility>
#include <iostream>
#include "../../../1sem/lab2/headers/Stack.h"
#include "../../lab1/headers/map.h"
using std::string, std::move, std::fstream, std::ios, std::cout, std::cin, std::stoi, std::fill, std::invalid_argument;
#ifndef ALGORITHMS_2SEM_LAB3_HEADERS_FlowNetwork_H_
#define ALGORITHMS_2SEM_LAB3_HEADERS_FlowNetwork_H_
const size_t MAX_NETWORK_SIZE = 1000;
class FlowNetwork {
 private:
  size_t network_[MAX_NETWORK_SIZE][MAX_NETWORK_SIZE] = {0};
  size_t size_ = 0;
  size_t source_;
  size_t sink_;
  string names_;
 public:
  void set_sink(const size_t sink);
  void set_size(const size_t size);
  void set_source(const size_t source);
  size_t get_source() const;
  size_t get_sink() const;
  size_t get_size() const;
  void add(const size_t vertex, const size_t edge, const size_t capacity);
  void read_network();
  bool BFS(const size_t *rGraph, size_t *parent);
  int Ford_Fulkerson();

};

#endif //ALGORITHMS_2SEM_LAB3_HEADERS_FlowNetwork_H_
