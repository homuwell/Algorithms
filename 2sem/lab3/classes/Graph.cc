#include "../headers/Graph.h"
#include <fstream>
Graph::Graph() {
  head_ = nullptr;
  last_ = nullptr;
}

Graph::vertex_ *Graph::find(const string &city) {
  auto *curr_elem = head_;
  while (curr_elem != nullptr) {
    if (curr_elem->city_ == city) {
      break;
    }
    curr_elem = curr_elem->next_;
  }
  return curr_elem;
}

void Graph::add_vertex(const string &in_city, const string &out_city, size_t in_cost, size_t out_cost) {
  if (head_ == nullptr) {
    auto *in_elem = new vertex_;
    in_elem->city_ = in_city;
    in_elem->next_ = nullptr;
    in_elem->edges_.head_ = nullptr;
    in_elem->edges_.last_ = nullptr;
    head_ = in_elem;
    auto *out_elem = new vertex_;
    out_elem->city_ = out_city;
    out_elem->next_ = nullptr;
    out_elem->edges_.head_ = nullptr;
    out_elem->edges_.last_ = nullptr;
    in_elem->next_ = out_elem;
    if (out_cost != -1) {
      out_elem->edges_.push_back(out_cost, in_elem);
    }
    if (in_cost != -1) {
      in_elem->edges_.push_back(in_cost, out_elem);
    }
    last_ = out_elem;
  } else {
    auto *in_elem = find(in_city);
    auto *out_elem = find(out_city);
    if (in_elem == nullptr) {
      in_elem = new vertex_;
      in_elem->city_ = in_city;
      in_elem->next_ = nullptr;
      in_elem->edges_.head_ = nullptr;
      in_elem->edges_.last_ = nullptr;
      last_->next_ = in_elem;
      last_ = in_elem;
    }
    if (out_elem == nullptr) {
      out_elem = new vertex_;
      out_elem->city_ = out_city;
      out_elem->next_ = nullptr;
      out_elem->edges_.head_ = nullptr;
      out_elem->edges_.last_ = nullptr;
      last_->next_ = out_elem;
      last_ = out_elem;
    }
    if (in_cost != -1) {
      in_elem->edges_.push_back(in_cost, out_elem);
    }
    if (out_cost != -1) {
      out_elem->edges_.push_back(out_cost, in_elem);
    }
  }
}

void Graph::input_cites() {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/lab3/in", ios::in);
  if (!in) {
    throw invalid_argument("Something went wrong while open in file");
  } else {
    char c;
    string str;
    while (!in.eof()) {
      string in_arr[4];
      int i = 0;
      while (in.get(c)) {
        if (c == '\n') {
          break;
        }
        if (c == ';') {
          i += 1;
          continue;
        }
        in_arr[i] += c;
      }
      if (in_arr[0].empty() || in_arr[1].empty() || in_arr[2].empty() || in_arr[3].empty()) {
        cout << "Incorrect string format, this line will not be included in graph";
        continue;
      }
      if (in_arr[0] == in_arr[1]) {
        cout << "Incorrect start point and end point, this line will not be included in graph";
        continue;
      }
      int in_cost, out_cost;
      size_t cost1, cost2;
      if (in_arr[2] == "N/A") {
        cost1 = -1;
      } else {
        in_cost = stoi(in_arr[2]);
        cost1 = in_cost;
        if (in_cost < 0) {
          cost1 = 0;
        }
      }
      if (in_arr[3] == "N/A") {
        cost2 = -1;
      } else {
        out_cost = stoi(in_arr[3]);
        cost2 = out_cost;
        if (out_cost < 0) {
          cost2 = 0;
        }
      }
      add_vertex(in_arr[0], in_arr[1], cost1, cost2);
    }

  }
}

size_t Graph::get_size() {
  if (head_ == nullptr) {
    return 0;
  }
  size_t size = 1;
  vertex_ *elem = head_;
  while (elem->next_ != nullptr) {
    size += 1;
    elem = elem->next_;
  }
  return size;
}

void Graph::create_route() {
  string way;
  int i, j;
  input_cites();
  string start, end;
  cout << "Please, insert start point of the route: ";
  cin >> start;
  cout << "Please, insert end point of the route: ";
  cin >> end;
  auto vertex = get_size();
  // vla is a feature of g++, not compile on MCVS and not part of C++ standard
  Node cites[vertex];
  vertex_ *curr_elem = head_;
  for (i = 0; i < get_size(); ++i) {
    cites[i].way_size_ = -1;
    cites[i].elem_ = curr_elem;
    cites[i].city_ = curr_elem->city_;
    cites[i].elem_->id = i;
    curr_elem = curr_elem->next_;
  }
  auto start_elem = find(start);
  auto end_elem = find(end);
  if (start_elem == nullptr) {
    cout << "Start point didn't exist" << endl;
    if (end_elem == nullptr) {
      cout << "End point didn't exist";
    }
  } else if (end_elem == nullptr) {
    cout << "End point didn't exist";
  } else {
    string curr_city = end;
    dijkstra(cites, vertex, start_elem, end_elem);
    for (i = 0; i < vertex; ++i) {
      if (curr_city == start) {
        way = curr_city + "->" + way;
        break;
      }
      for (j = 0; j < vertex; ++j) {
        if (cites[j].city_ == curr_city) {
          if (curr_city == end) {
            way += curr_city;
            curr_city = cites[j].elem_->city_;
            break;
          } else {
            way = curr_city + "->" + way;
            curr_city = cites[j].elem_->city_;
            break;
          }
        }
      }
    }
    for (i = 0; i < vertex; ++i) {
      if (cites[i].city_ == end) {
        if (cites[i].way_size_ != -1) {
          cout << "Cost: " << cites[i].way_size_ << endl;
          cout << "Route: " << way;
          break;
        } else {
          cout << "The route between " << start << " and " << end << " didn't exist";
          break;
        }
      }
    }
  }
}

void Graph::dijkstra(Node *arr, size_t arr_size, vertex_ *start, vertex_ *end) {
  int i = 0;
  int start_elem_index = 0;
  for (i = 0; i < arr_size; ++i) { // find start element and set it weight as final
    if (arr[i].elem_ == start) {
      arr[i].way_size_ = 0;
      arr[i].stable = true;
      start_elem_index = i;
      break;
    }
  }
  size_t min_way = -1;
  vertex_ *curr_vertex = start;
  arr[start_elem_index].elem_ = nullptr; //field elem using to restore shortest path
  // start element can't have previous element so we set elem_ as nullptr
  for (i = 0; i < arr_size - 1; ++i) { //
    if (curr_vertex->edges_.head_ == nullptr) { // if vertex don't have any edges
      break;
    } else {
      auto curr_edge = curr_vertex->edges_.head_; // set first edge
      while (curr_edge != nullptr) { // see all edges of the current vertex
        if (arr[curr_edge->city_->id].way_size_ > arr[curr_vertex->id].way_size_ + curr_edge->weight_
            && !arr[curr_edge->city_->id].stable) {
          // if sum is greater we set way_size to sum
          arr[curr_edge->city_->id].way_size_ = arr[curr_vertex->id].way_size_ + curr_edge->weight_;
          // setting prev city
          arr[curr_edge->city_->id].elem_ = curr_vertex;
        }
        curr_edge = curr_edge->next_; // go to next edge
      }
    }
    min_way = -1;
    int id;
    arr[curr_vertex->id].stable = true; // mark current vertex weight as final
    for (int i = 0; i < arr_size; ++i) { // find element with minimal weight
      if (arr[i].way_size_ < min_way && !arr[i].stable) {
        min_way = arr[i].way_size_;
        id = i;
      }
    }
    curr_vertex = find(arr[id].city_); // set current vertex to vertex with minimal weight
  }
}
void Graph::clear_graph() noexcept {
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

Graph::~Graph() noexcept {
  clear_graph();
}
void Graph::pop_front() noexcept {
  if (head_ == nullptr) {
    return;
  }
  if (head_->next_ != nullptr) {
    auto next_elem = head_->next_;
    head_->next_ = nullptr;
    delete head_;
    head_ = next_elem;
  } else {
    delete head_;
  }
}

size_t Graph::create_route(const string &start, const string &end) {
  string way;
  int i, j = 0;
  input_cites();
  auto vertex = get_size();
  // vla is a feature of g++, not compile on MCVS and not part of C++ standard
  Node cites[vertex];
  vertex_ *curr_elem = head_;
  for (i = 0; i < get_size(); ++i) {
    cites[i].way_size_ = -1;
    cites[i].elem_ = curr_elem;
    cites[i].city_ = curr_elem->city_;
    cites[i].elem_->id = i;
    curr_elem = curr_elem->next_;
  }
  auto start_elem = find(start);
  auto end_elem = find(end);
  if (start_elem == nullptr) {
    cout << "Start point didn't exist" << endl;
    if (end_elem == nullptr) {
      cout << "End point didn't exist";
    }
  } else if (end_elem == nullptr) {
    cout << "End point didn't exist";
  } else {
    string curr_city = end;
    dijkstra(cites, vertex, start_elem, end_elem);
    for (i = 0; i < vertex; ++i) {
      if (curr_city == start) {
        way = curr_city + "->" + way;
        break;
      }
      for (j = 0; j < vertex; ++j) {
        if (cites[j].city_ == curr_city) {
          if (curr_city == end) {
            way += curr_city;
            curr_city = cites[j].elem_->city_;
            break;
          } else {
            way = curr_city + "->" + way;
            curr_city = cites[j].elem_->city_;
            break;
          }
        }
      }
    }
    for (i = 0; i < vertex; ++i) {
      if (cites[i].city_ == end) {
        if (cites[i].way_size_ != -1) {
          return cites[i].way_size_;
        } else {
          return -1;
        }
      }
    }
  }
}