#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/List.h"
#include <fstream>
using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  List obj;
  ClassDeclaration() {
    obj;
  }
};
}
TEST_F(ClassDeclaration, push_backTest1) {
  obj.push_back(15);
  ASSERT_EQ(15, obj.head->info);
}
TEST_F(ClassDeclaration, push_backTest2) {
  obj.push_back(15);
  obj.push_back(20);
  ASSERT_EQ(20, obj.last->info);
}
TEST_F(ClassDeclaration, push_frontTest1) {
  obj.push_front(20);
  ASSERT_EQ(20, obj.head->info);
}
TEST_F(ClassDeclaration, push_frontTest2) {
  obj.push_front(15);
  obj.push_front(20);
  ASSERT_EQ(20, obj.head->info);
}
TEST_F(ClassDeclaration, pop_frontTest1) { //when list is empty
  try {
    obj.pop_front();
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, the List is empty");
  }
}
TEST_F(ClassDeclaration, pop_frontTest2) { //when list have only one element
  obj.push_back(15);
  obj.pop_front();
  ASSERT_EQ(nullptr, obj.head);
}
TEST_F(ClassDeclaration, pop_frontTest3) { //when list have more than 1 element
  obj.push_back(15);
  obj.push_back(25);
  obj.push_back(55);
  obj.pop_front();
  ASSERT_EQ(25, obj.head->info);
}
TEST_F(ClassDeclaration, pop_backTest1) { //when list is empty
  try {
    obj.pop_back();
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, the List is empty");
  }
}
TEST_F(ClassDeclaration, pop_backTest2) { //when list have only one element
  obj.push_back(25);
  obj.pop_back();
  ASSERT_EQ(nullptr, obj.last);
}
TEST_F(ClassDeclaration, pop_backTest3) { //when list have more than 1 element
  obj.push_back(15);
  obj.push_back(25);
  obj.pop_back();
  ASSERT_EQ(15, obj.last->info);
}
TEST_F(ClassDeclaration, insertTest1) { // test exception
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  try {
    obj.insert(14, 20);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, id number is larger than size of list");
  }
}
TEST_F(ClassDeclaration, insertTest2) { //insert in beginning of the list
  obj.insert(15, 0);
  ASSERT_EQ(15, obj.head->info);
}
TEST_F(ClassDeclaration, insertTest3) { //insert in middle of the list
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  obj.insert(18, 3);
  ASSERT_EQ(18, obj.at(3));
}
TEST_F(ClassDeclaration, atTest1) {
  try {
    obj.at(0);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, the List is empty");
  }
}
TEST_F(ClassDeclaration, atTest2) {
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  try {
    obj.at(20);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, id number is larger than size of list");
  }
}
TEST_F(ClassDeclaration, atTest3) { //get value of the first element
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  ASSERT_EQ(10, obj.at(0));
}
TEST_F(ClassDeclaration, atTest4) { //get value of the element somewhere in middle
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  ASSERT_EQ(20, obj.at(2));
}
TEST_F(ClassDeclaration, atTest5) { //get value of the last element
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  ASSERT_EQ(25, obj.at(3));
}
TEST_F(ClassDeclaration, removeTest1) {
  try {
    obj.remove(0);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, the List is empty");
  }
}
TEST_F(ClassDeclaration, removeTest2) {
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  try {
    obj.remove(20);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, id number is larger than size of list");
  }
}
TEST_F(ClassDeclaration, removeTest3) { //remove in list with one element
  obj.push_back(22);
  obj.remove(0);
  ASSERT_EQ(nullptr, obj.head);
}
TEST_F(ClassDeclaration, removeTest4) { //remove in list from last
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  obj.remove(3);
  ASSERT_EQ(20, obj.last->info);
}
TEST_F(ClassDeclaration, removeTest5) { //remove element somewhere in middle of the list
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  obj.remove(1);
  ASSERT_EQ(20, obj.at(1));
}
TEST_F(ClassDeclaration, isEmptyTest1) { //empty list
  ASSERT_EQ(true, obj.isEmpty());
}
TEST_F(ClassDeclaration, isEmptyTest2) { //list without element
  obj.push_back(5);
  ASSERT_EQ(false, obj.isEmpty());
}
TEST_F(ClassDeclaration, get_sizeTest1) { //empty list
  ASSERT_EQ(0, obj.get_size());
}
TEST_F(ClassDeclaration, get_sizeTest2) { //list with one element
  obj.push_back(55);
  ASSERT_EQ(1, obj.get_size());
}
TEST_F(ClassDeclaration, get_sizeTest3) { //list with more than one element
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  ASSERT_EQ(4, obj.get_size());
}
TEST_F(ClassDeclaration, clearTest1) { //list with one element
  obj.push_back(10);
  obj.clear();
  ASSERT_EQ(nullptr, obj.head);
}
TEST_F(ClassDeclaration, clearTest2) { //list with  more than one element
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  obj.clear();
  ASSERT_EQ(nullptr, obj.head);
}
TEST_F(ClassDeclaration, setTest1) {
  try {
    obj.set(5, 0);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, the List is empty");
  }
}
TEST_F(ClassDeclaration, setTest2) {
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  try {
    obj.set(25, 4);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, id number is larger than size of list");
  }
}
TEST_F(ClassDeclaration, setTest3) { //list with more than one element
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  obj.set(2, 11);
  ASSERT_EQ(11, obj.at(2));
}
TEST_F(ClassDeclaration, find_firstTest1) {
  List obj1;
  obj1.push_back(5);
  try {
    obj.find_first(obj1);
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Error, some of the List is Empty");
  }
}
TEST_F(ClassDeclaration, find_firstTest2) { // List 1 don't contain List 2
  List obj1;
  obj1.push_back(23);
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  ASSERT_EQ(0, obj.find_first(obj1));
}
TEST_F(ClassDeclaration, find_firstTest3) {
  List obj1;
  obj1.push_back(15);
  obj1.push_back(20);
  obj.push_back(10);
  obj.push_back(15);
  obj.push_back(20);
  obj.push_back(25);
  ASSERT_EQ(1, obj.find_first(obj1));
}
