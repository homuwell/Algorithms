#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/Tree.h"

using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  Tree obj;
  ClassDeclaration() {
    obj;
  }
};
}
TEST_F(ClassDeclaration, printTest) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  obj.insert(3);
  obj.insert(8);
  obj.insert(8123123);
  obj.print(obj.head, "  ", "");
}
TEST_F(ClassDeclaration, ContainsTest1) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  ASSERT_EQ(true, obj.contains(7));
}
TEST_F(ClassDeclaration, ContainsTest2) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  ASSERT_EQ(false, obj.contains(123));
}
TEST_F(ClassDeclaration, removeTest2) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  obj.remove(10);
  ASSERT_EQ(false, obj.contains(10));
}
TEST_F(ClassDeclaration, removeTest1) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  obj.remove(45);
  ASSERT_EQ(false, obj.contains(45));
}
TEST_F(ClassDeclaration, removeTest3) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(35);
  obj.insert(22);
  obj.remove(40);
  ASSERT_EQ(false, obj.contains(40));
}
TEST_F(ClassDeclaration, insertTest1) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(35);
  obj.insert(45);
  obj.insert(7);
  ASSERT_EQ(true, obj.contains(7));
}
TEST_F(ClassDeclaration, insertTest2) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(35);
  obj.insert(45);
  obj.insert(7);
  obj.insert(18);
  ASSERT_EQ(true, obj.contains(18));
}
TEST_F(ClassDeclaration, DFStest) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  Iterator *element = obj.create_DFT_Iterator(obj.head);
  bool flag;
  int i;
  i = 0;
  flag = true;
  int arr[7] = {20, 10, 7, 18, 40, 35, 45};
  while (element->has_next()) {
    if (arr[i] != element->next()) {
      flag = false;
      break;
    }
    i++;
  }
  ASSERT_EQ(flag, true);
}
TEST_F(ClassDeclaration, BFStest) {
  obj.insert(20);
  obj.insert(40);
  obj.insert(10);
  obj.insert(7);
  obj.insert(18);
  obj.insert(35);
  obj.insert(45);
  Iterator *element = obj.create_BFT_Iterator(obj.head);
  bool flag;
  int i;
  i = 0;
  flag = true;
  int arr[7] = {20, 10, 40, 7, 18, 35, 45};
  while (element->has_next()) {
    if (arr[i] != element->next()) {
      flag = false;
      break;
    }
    i++;
  }
  ASSERT_EQ(flag, true);
}
