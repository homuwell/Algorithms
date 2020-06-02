#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include <iostream>
using std::string, std::move, std::fstream, std::ios, std::cout,
std::cin, std::stoi, std::reverse, std::invalid_argument, std::endl;
#ifndef ALGORITHMS_2SEM_LAB3_HEADERS_GRAPH_H_
#define ALGORITHMS_2SEM_LAB3_HEADERS_GRAPH_H_
class Graph {
 private:
  struct vertex_ {
    size_t id;
    string city_;
    vertex_ *next_;
    struct Edges {
     public:
      struct edge_ {
        size_t weight_;
        vertex_ *city_;
        edge_ *next_;
      };
      edge_ *head_;
      edge_ *last_;
      Edges();
      ~Edges() noexcept;
      void push_back(size_t weight, vertex_ *city);
      void pop_front();
      void clear() noexcept;
    };
    Edges edges_;
  };
  struct Node {
    string city_;
    vertex_ *elem_;
    size_t way_size_;
    bool stable;
    Node() {
      elem_ = nullptr;
      way_size_ = -1;
      stable = false;
    }
  };
  vertex_ *head_;
  vertex_ *last_;
 public:
  Graph();
  ~Graph() noexcept;
  void pop_front() noexcept;
  void clear_graph() noexcept;
  void add_vertex(const string &in_city, const string &out_city, size_t in_cost, size_t out_cost);
  vertex_ *find(const string &city);
  void input_cites();
  void create_route();
  size_t create_route(const string &start, const string &end);
  void dijkstra(Node *arr, size_t arr_size, vertex_ *start, vertex_ *end);
  size_t get_size();
};

#endif //ALGORITHMS_2SEM_LAB3_HEADERS_GRAPH_H_
