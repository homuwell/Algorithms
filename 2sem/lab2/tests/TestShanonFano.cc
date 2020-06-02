#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/ShannonFano.h"
#include "../headers/SFTree.h"
#include "../headers/SymbolsList.h"
using testing::Eq;
namespace {
class ClassDeclaration : public testing::Test {
 public:
  ShannonFano obj;

  ClassDeclaration() {
    obj;
  }
};
}
TEST_F(ClassDeclaration, TreeCreation
) {
bool flag = false;
SymbolsList *list = new SymbolsList;
SFTree *tree = new SFTree;
list->push_back('c');
list->push_back('k');
list->push_back('v');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('k');
list->update_frequency('k');
list->update_frequency('v');
string out;
size_t cap = 0;
for (
int i = 0;
i<list->
get_size();
++i) {
out += list->
get_symbol(i);
cap += list->
get_frequency(i);
}
tree->
add(out, cap
);
tree->create_tree(0,list->
get_size()
-1,list,tree->
get_root()
);
if (tree->get_root()->left->capacity_ == 5 &&
tree->get_root()->right->right->capacity_ == 2 &&
tree->get_root()->right->left->capacity_ == 3)  {
flag = true;
}
ASSERT_EQ(flag,
true);
}

TEST_F(ClassDeclaration, TreeCodes
) {
bool flag = false;
SymbolsList *list = new SymbolsList;
SFTree *tree = new SFTree;
list->push_back('c');
list->push_back('k');
list->push_back('v');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('k');
list->update_frequency('k');
list->update_frequency('v');
string out;
size_t cap = 0;
for (
int i = 0;
i<list->
get_size();
++i) {
out += list->
get_symbol(i);
cap += list->
get_frequency(i);
}
tree->
add(out, cap
);
tree->create_tree(0,list->
get_size()
-1,list,tree->
get_root()
);
if (tree->get_code('c') == "0" &&
tree->get_code('k') == "10" &&
tree->get_code('v') == "11")  {
flag = true;
}
ASSERT_EQ(flag,
true);
}

TEST_F(ClassDeclaration, TreeSymbols
) {
bool flag = false;
SymbolsList *list = new SymbolsList;
SFTree *tree = new SFTree;
list->push_back('c');
list->push_back('k');
list->push_back('v');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('k');
list->update_frequency('k');
list->update_frequency('v');
list->push_back('p');
list->update_frequency('p');
list->update_frequency('p');
list->update_frequency('p');
string out;
size_t cap = 0;
for (
int i = 0;
i<list->
get_size();
++i) {
out += list->
get_symbol(i);
cap += list->
get_frequency(i);
}
tree->
add(out, cap
);
tree->create_tree(0,list->
get_size()
-1,list,tree->
get_root()
);
auto a = tree->get_code('c');
auto b = tree->get_code('k');
auto c = tree->get_code('v');
auto d = tree->get_code('p');
if (tree->get_symbol_from_code("01") == 'k' &&
tree->get_symbol_from_code("00") == 'c' &&
tree->get_symbol_from_code("10") == 'v' &&
tree->get_code('p') == "11")  {
flag = true;
}
ASSERT_EQ(flag,
true);
}

TEST_F(ClassDeclaration, ListSortReverse
) {
bool flag = true;
SymbolsList *list = new SymbolsList;
list->push_back('k');
list->push_back('v');
list->push_back('p');
list->push_back('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('k');
list->update_frequency('k');
list->update_frequency('v');
list->
sort();
size_t arr[4] = {5, 3, 2, 1};
for(
int i = 0;
i<list->
get_size();
++i) {
if (list->
get_frequency(i)
!= arr[i]) {
flag = false;
break;
}
}
ASSERT_EQ(flag,
true);
}
TEST_F(ClassDeclaration, ListReverse
) {
bool flag = true;
SymbolsList *list = new SymbolsList;
list->push_back('k');
list->push_back('v');
list->push_back('p');
list->push_back('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('c');
list->update_frequency('k');
list->update_frequency('k');
list->update_frequency('v');
list->
sort();
list->
reverse();
size_t arr[4] = {1, 2, 3, 5};
for(
int i = 0;
i<list->
get_size();
++i) {
if (list->
get_frequency(i)
!= arr[i]) {
flag = false;
break;
}
}
ASSERT_EQ(flag,
true);
}
TEST_F(ClassDeclaration, EncodeTest
) {
ASSERT_EQ(obj
.encode("Kept you waiting, hah?"),"100001000110010010001010010101101100011000010001010010101110011101111000001101000111111");
}
TEST_F(ClassDeclaration, DecodeTest
) {
string s = "Why are we still here?"
           "Just to suffer?"
           "Every night, I can feel my leg… and my arm… even my fingers. "
           "The body I’ve lost… the comrades I’ve lost… "
           "won’t stop hurting… "
           "It’s like they’re all still there."
           "You feel it, too, don’t you?";

ASSERT_EQ(obj
.
decode(obj
.
encode(s)
),s);
}
