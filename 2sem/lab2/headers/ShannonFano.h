#include <string>
#include <iostream>
#include "../headers/SymbolsList.h"
#include "../../lab1/headers/map.h"
#include "../headers/SFTree.h"
using namespace std;
#ifndef ALGORITHMS_2SEM_LAB2_HEADERS_SHANNON_FANO_H_
#define ALGORITHMS_2SEM_LAB2_HEADERS_SHANNON_FANO_H_
class ShannonFano {
 private:
  SFTree tree_;
  void print_info();
  string get_symbols(SymbolsList *list, const string &input);
  void shannon_fano(size_t begin, size_t end, SymbolsList *list);
 public:
  string encode();
  string encode(const string &input);
  string decode(const string &in);
};
#endif //ALGORITHMS_2SEM_LAB2_HEADERS_SHANNON_FANO_H_
