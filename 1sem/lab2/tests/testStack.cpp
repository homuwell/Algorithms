#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/Stack.h"

using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  Stack<int> obj;
  ClassDeclaration() {
    obj;
  }
};
}
TEST_F(ClassDeclaration, pushTest1) { //empty stack
  obj.push(5);
  ASSERT_EQ(5, obj.peek());
}
TEST_F(ClassDeclaration, pushTest2) { // not empty stack
  obj.push(5);
  obj.push(10);
  ASSERT_EQ(10, obj.peek());
}
TEST_F(ClassDeclaration, popTest1) { // not empty stack
  obj.push(5);
  obj.push(10);
  ASSERT_EQ(10, obj.pop());
}
TEST_F(ClassDeclaration, popTest2) { //empty stack
  try {
    obj.pop();
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Stack is Empty");
  }
}
TEST_F(ClassDeclaration, get_sizeTest1) { // stack with one element
  ASSERT_EQ(0, obj.get_size());
}
TEST_F(ClassDeclaration, get_sizeTest2) { // stack with one element
  obj.push(5);
  ASSERT_EQ(1, obj.get_size());
}
TEST_F(ClassDeclaration, get_sizeTest3) { //stack with more than one element
  obj.push(5);
  obj.push(10);
  obj.push(20);
  ASSERT_EQ(3, obj.get_size());
}
TEST_F(ClassDeclaration, peekTest1) {
  obj.push(5);
  obj.push(135);
  ASSERT_EQ(135, obj.peek());
}
TEST_F(ClassDeclaration, peekTest2) {
  try {
    obj.peek();
    FAIL();
  }
  catch (const out_of_range &e) {
    ASSERT_STREQ(e.what(), "Stack is Empty");
  }
}
