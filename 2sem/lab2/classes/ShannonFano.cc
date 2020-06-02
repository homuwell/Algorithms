#include "../headers/ShannonFano.h"
#include <cmath>
using std::cout, std::cin;
string ShannonFano::get_symbols(SymbolsList *list, const string &input) {
  ;
  for (char i : input) {
    list->update_frequency(i);
  }
  list->sort();
  return input;
}
void ShannonFano::shannon_fano(size_t begin, size_t end, SymbolsList *list) {
  tree_.create_tree(begin, end, list, tree_.get_root());
}

string ShannonFano::encode() {
  string input;
  auto *list = new SymbolsList;
  getline(cin, input);
  string in = get_symbols(list, input);
  string out;
  size_t cap = 0;
  for (int i = 0; i < list->get_size(); ++i) {
    out += list->get_symbol(i);
    cap += list->get_frequency(i);
  }
  tree_.add(out, cap);
  shannon_fano(0, list->get_size() - 1, list);
  print_info();
  cout << "size of input string:" << in.size() * 8 << endl << endl;
  out = "";
  for (char i : in) {
    out += tree_.get_code(i);
  }
  cout << "size of output string:" << out.size() << endl << endl;
  cout << "compression ratio: " << static_cast<double>(in.size() * 8) / out.size() << endl << endl;
  return out;
}

string ShannonFano::decode(const string &in) {
  string out;
  string buff;
  char symbol;
  for (char i : in) {
    buff += i;
    symbol = tree_.get_symbol_from_code(buff);
    if (symbol != '\n') {
      out += symbol;
      buff = "";
    }
  }
  return out;
}

void ShannonFano::print_info() {
  cout << "Shannon-Fano Tree:" << endl;
  tree_.print(tree_.get_root());
  cout << endl;
  cout << "Codes for every element: " << endl;
  tree_.print_symbols_and_codes(tree_.get_root(), "");
  cout << endl;
}
string ShannonFano::encode(const string &input) {
  auto *list = new SymbolsList;
  string in = get_symbols(list, input);
  string out;
  size_t cap = 0;
  for (int i = 0; i < list->get_size(); ++i) {
    out += list->get_symbol(i);
    cap += list->get_frequency(i);
  }
  tree_.add(out, cap);
  out = "";
  shannon_fano(0, list->get_size() - 1, list);
  for (char i : in) {
    out += tree_.get_code(i);
  }
  return out;
}
