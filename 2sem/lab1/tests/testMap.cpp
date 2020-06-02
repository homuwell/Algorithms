#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/map.h"

using testing::Eq;
namespace {
class ClassDeclaration : public testing::Test {
 public:
  Map<int, string> obj;

  ClassDeclaration() {
    obj;
  }
};
}
TEST_F(ClassDeclaration, insertTest1) { //uncle is red right
  obj.insert(10, "car");
  obj.insert(15, "chair");
  obj.insert(5, "bed");
  obj.insert(8, "table");
  ASSERT_EQ(obj.find(8)->value, "table");
}

TEST_F(ClassDeclaration, insertTest2) { //uncle is red left
  obj.insert(10, "car");
  obj.insert(15, "chair");
  obj.insert(5, "bed");
  obj.insert(3, "keyboard");
  ASSERT_EQ(obj.find(3)->value, "keyboard");
}

TEST_F(ClassDeclaration, insertTest3) { //uncle is black and element is right child right
  obj.insert(10, "car");
  obj.insert(15, "chair");
  obj.insert(20, "bed");
  ASSERT_EQ(obj.find(20)->value, "bed");
}

TEST_F(ClassDeclaration, insertTest4) { //uncle is black and element is right child left
  obj.insert(10, "car");
  obj.insert(5, "chair");
  obj.insert(8, "bed");
  ASSERT_EQ(obj.find(8)->value, "bed");
}

TEST_F(ClassDeclaration, insertTest5) { //uncle is black and element is left child right
  obj.insert(10, "car");
  obj.insert(15, "chair");
  obj.insert(12, "bed");
  ASSERT_EQ(obj.find(12)->value, "bed");
}

TEST_F(ClassDeclaration, insertTest6) { //uncle is black and element is left child left
  obj.insert(10, "car");
  obj.insert(5, "chair");
  obj.insert(2, "bed");
  ASSERT_EQ(obj.find(2)->value, "bed");
}

TEST_F(ClassDeclaration, deleteTest4) { //brother is black and right child is red left
  obj.insert(5, "car");
  obj.insert(4, "chair");
  obj.insert(8, "bed");
  obj.insert(10, "chair");
  obj.insert(7, "bed");
  obj.remove(4);
  obj.find(4);
  ASSERT_EQ(obj.find(30), nullptr);
}

TEST_F(ClassDeclaration, deleteTest8) { //brother is black and right child is red right
  obj.insert(10, "car");
  obj.insert(15, "chair");
  obj.insert(4, "bed");
  obj.insert(6, "chair");
  obj.insert(3, "bed");
  obj.remove(15);
  obj.find(30);
  ASSERT_EQ(obj.find(15), nullptr);
}

TEST_F(ClassDeclaration, deleteTest1) { //brother is red  left
  obj.insert(4, "car");
  obj.insert(3, "chair");
  obj.insert(10, "bed");
  obj.insert(6, "chair");
  obj.insert(12, "bed");
  obj.insert(16, "bed");
  obj.remove(3);
  obj.find(3);
  ASSERT_EQ(obj.find(30), nullptr);
}

TEST_F(ClassDeclaration, deleteTest5) { //brother is red  right
  obj.insert(20, "car");
  obj.insert(30, "chair");
  obj.insert(10, "bed");
  obj.insert(15, "chair");
  obj.insert(3, "bed");
  obj.insert(16, "bed");
  obj.remove(30);
  obj.find(30);
  ASSERT_EQ(obj.find(30), nullptr);

}

TEST_F(ClassDeclaration, keysTest) {
  obj.insert(4, "car");
  obj.insert(3, "chair");
  obj.insert(10, "bed");
  obj.insert(6, "chair");
  obj.insert(12, "bed");
  obj.insert(16, "bed");
  List<int> *list = obj.get_keys();
  List<int> *list2 = new List<int>;
  list2->push_back(3);
  list2->push_back(4);
  list2->push_back(6);
  list2->push_back(10);
  list2->push_back(12);
  list2->push_back(16);
  ASSERT_EQ(obj.check(list, list2), true);
}

TEST_F(ClassDeclaration, valuesTest) {
  obj.insert(4, "car");
  obj.insert(3, "chair");
  obj.insert(10, "bed");
  obj.insert(6, "table");
  obj.insert(12, "apple");
  obj.insert(16, "mirror");
  List<string> *list = obj.get_values();
  List<string> *list2 = new List<string>;
  list2->push_back("chair");
  list2->push_back("car");
  list2->push_back("table");
  list2->push_back("bed");
  list2->push_back("apple");
  list2->push_back("mirror");
  ASSERT_EQ(obj.check(list, list2), true);
}

TEST_F(ClassDeclaration, clearTest) {
  obj.insert(4, "car");
  obj.insert(3, "chair");
  obj.insert(10, "bed");
  obj.insert(6, "chair");
  obj.insert(12, "bed");
  obj.insert(16, "bed");
  obj.clear();
  ASSERT_EQ(obj.isEmpty(), true);
}

TEST_F(ClassDeclaration, EmptyKeys) {
  try {
    obj.get_keys();
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Array is empty");
  }
}

TEST_F(ClassDeclaration, EmptyValues) {
  try {
    obj.get_values();
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Array is empty");
  }
}

TEST_F(ClassDeclaration, EmptyRemove) {
  try {
    obj.remove(100);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Key does not exist in array");
  }
}

TEST_F(ClassDeclaration, EmptyCheck1) {
  obj.insert(4, "car");
  obj.insert(3, "chair");
  obj.insert(10, "bed");
  obj.insert(6, "table");
  obj.insert(12, "apple");
  obj.insert(16, "mirror");
  List<string> *list = obj.get_values();
  List<string> *list2 = new List<string>;
  try {
    obj.check(list, list2);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "At least one of the List is Empty");
  }
}

TEST_F(ClassDeclaration, EmptyCheck2) {
  obj.insert(4, "car");
  obj.insert(3, "chair");
  obj.insert(10, "bed");
  obj.insert(6, "table");
  obj.insert(12, "apple");
  obj.insert(16, "mirror");
  auto *list = obj.get_values();
  auto *list2 = new List<string>;
  try {
    obj.check(list2, list);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "At least one of the List is Empty");
  }
}

TEST_F(ClassDeclaration, TwoSameKeys) {
  obj.insert(4, "car");
  try {
    obj.insert(4, "chair");
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "This key already exist in array");
  }
}