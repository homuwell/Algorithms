#include "../headers/FlowNetwork.h"
#include <fstream>
#include <utility>
#include "cstring"
#include "../headers/Queue.h"

void FlowNetwork::read_network() {
  fstream in;
  size_t vertex, edge;
  bool source = false, sink = false;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::in);
  if (!in) {
    throw invalid_argument("Something went wrong while open in file");
  } else {
    char c;
    string str;
    while (!in.eof()) {
      string in_arr[3];
      int i = 0;
      while (in.get(c)) {
        if (c == '\n') {
          break;
        }
        if (c == ' ') {
          i += 1;
          continue;
        }
        in_arr[i] += c;
      }
      if (in_arr[0] == "S" || in_arr[1] == "S") {
        source = true;
      }
      if (in_arr[1] == "T" || in_arr[0] == "T") {
        sink = true;
      }
      if (in_arr[0].empty() || in_arr[1].empty() || in_arr[2].empty() ||
          in_arr[0] == in_arr[1] ||
          in_arr[0].length() > 1 || in_arr[1].length() > 1
          ) {
        cout << "Incorrect input, this line will not be included in net";
        continue;
      }
      if (in_arr[0] == in_arr[1]) {
        cout << "Incorrect start point and end point, this line will not be included in FlowNetwork";
        continue;
      }
      int cost;
      size_t in_cost;
      cost = stoi(in_arr[2]);
      in_cost = cost;
      if (cost < 0) {
        in_cost = 0;
      }
      auto vert = names_.find(in_arr[0]);
      auto ed = names_.find(in_arr[1]);
      if (vert == string::npos) {
        names_.append(in_arr[0]);
        size_ += 1;
        vertex = names_.find(in_arr[0]);
        if (in_arr[0] == "S") {
          source_ = vertex;
        }
        if (in_arr[0] == "T") {
          sink_ = vertex;
        }
      } else {
        vertex = vert;
      }
      if (ed == string::npos) {
        names_.append(in_arr[1]);
        size_ += 1;
        edge = names_.find(in_arr[1]);
        if (in_arr[1] == "S") {
          source_ = edge;
        }
        if (in_arr[1] == "T") {
          sink_ = edge;
        }
      } else {
        edge = ed;
      }
      if (size_ >= MAX_NETWORK_SIZE) {
        throw out_of_range("Network too big");
      }
      add(vertex, edge, in_cost);
    }
  }
  if (!sink) {
    throw invalid_argument("Sink aren't marked");
  }
  if (!source) {
    throw invalid_argument("Source aren't marked");
  }
  in.close();
}

void FlowNetwork::add(const size_t vertex, const size_t edge, const size_t capacity) {
  network_[vertex][edge] = capacity;
}

bool FlowNetwork::BFS(const size_t *rGraph, size_t *parent) {
  bool visited[size_];
  fill(&visited[0], &visited[size_], 0);
  Queue<size_t> q;
  q.push(source_);
  visited[source_] = true;
  parent[source_] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < size_; v++) {
      if (!visited[v] && rGraph[u * size_ + v] > 0) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return visited[sink_];
}

int FlowNetwork::Ford_Fulkerson() {
  int i, j;
  size_t residual_network[size_][size_];
  for (i = 0; i < size_; ++i) { //create and fill residual network
    for (j = 0; j < size_; ++j) {
      residual_network[i][j] = network_[i][j];
    }
  }
  size_t augmenting_path[size_];
  size_t max_flow = 0;
  while (BFS(*residual_network, augmenting_path)) { // while we can find path
    size_t path_flow = -1;
    string path;
    path = names_[sink_]; //set last point
    for (j = sink_; j != source_; j = augmenting_path[j]) { // getting lower capacity in this path
      i = augmenting_path[j];
      path = names_[augmenting_path[j]] + path; // restore path in reverse order
      path_flow = min(path_flow, residual_network[i][j]); // set flow in this augmenting path
    }
    cout << "Path: ";
    for (auto s : path) { //print current path
      if (s == 'T') {
        cout << s;
        break;
      }
      cout << s << "->";
    }
    cout << " flow: " << path_flow; // print flow in this path
    cout << endl;
    for (j = sink_; j != source_; j = augmenting_path[j]) { // setting capacities in augmenting path
      i = augmenting_path[j];
      residual_network[i][j] -= path_flow;
      residual_network[j][i] += path_flow;
    }
    max_flow += path_flow; // update flow of the network
  }
  return max_flow;
}

void FlowNetwork::set_size(const size_t size) {
  if (size >= MAX_NETWORK_SIZE) {
    throw invalid_argument("Size can't be more than max size");
  } else if (size < size_) {
    throw invalid_argument("Size can't be less than current");
  } else {
    size_ = size;
  }
}

void FlowNetwork::set_sink(const size_t sink) {
  if (sink >= size_) {
    throw invalid_argument("Sink out of matrix");
  } else {
    sink_ = sink;
  }
}

void FlowNetwork::set_source(const size_t source) {
  if (source >= size_) {
    throw invalid_argument("Source out of matrix");
  } else {
    source_ = source;
  }
}

size_t FlowNetwork::get_source() const {
  return source_;
}

size_t FlowNetwork::get_sink() const {
  return sink_;
}

size_t FlowNetwork::get_size() const {
  return size_;
}
