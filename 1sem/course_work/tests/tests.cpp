#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Backpack.cpp"

using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  ClassDeclaration() = default;
};
}
TEST_F(ClassDeclaration, AnsTest) {
  bool flag = true;
  //BackPackFunc();
  int **A = new int *[3];
  for (int i = 0; i < 3; i++) {
    A[i] = new int[6];
  }
  A[0][0] = 0;
  A[0][1] = 0;
  A[0][2] = 0;
  A[0][3] = 0;
  A[0][4] = 0;
  A[0][5] = 0;
  A[1][0] = 0;
  A[1][1] = 0;
  A[1][2] = 500;
  A[1][3] = 500;
  A[1][4] = 500;
  A[1][5] = 500;
  A[2][0] = 0;
  A[2][1] = 0;
  A[2][2] = 500;
  A[2][3] = 500;
  A[2][4] = 500;
  A[2][5] = 1000;
  Item *elems = new Item[3];
  elems[1].pieces = 1;
  elems[1].weight = 2;
  elems[1].cost = 500;
  elems[1].name = 1;
  elems[1].NameOfItem = 'map';
  elems[2].pieces = 1;
  elems[2].weight = 3;
  elems[2].cost = 500;
  elems[2].name = 2;
  elems[2].NameOfItem = 'knife';
  int *a = new int[3];
  a[0] = 0;
  a[1] = 0;
  a[2] = 0;
  int TestArr[3] = {0, 1, 1};
  findAns(A, 2, 5, elems, a);
  for (int i = 0; i < 3; i++) {
    if (a[i] != TestArr[i]) {
      flag = false;
    }
  }
  ASSERT_EQ(flag, true);
}
TEST_F(ClassDeclaration, AnsTest2) {
  bool flag = true;
  //BackPackFunc();
  int **A = new int *[3];
  for (int i = 0; i < 3; i++) {
    A[i] = new int[6];
  }
  A[0][0] = 0;
  A[0][1] = 0;
  A[0][2] = 0;
  A[0][3] = 0;
  A[0][4] = 0;
  A[0][5] = 0;
  A[1][0] = 0;
  A[1][1] = 0;
  A[1][2] = 500;
  A[1][3] = 500;
  A[1][4] = 500;
  A[1][5] = 500;
  A[2][0] = 0;
  A[2][1] = 0;
  A[2][2] = 500;
  A[2][3] = 500;
  A[2][4] = 500;
  A[2][5] = 1000;
  Item *elems = new Item[3];
  elems[1].pieces = 1;
  elems[1].weight = 2;
  elems[1].cost = 500;
  elems[1].name = 1;
  elems[1].NameOfItem = 'map';
  elems[2].pieces = 1;
  elems[2].weight = 3;
  elems[2].cost = 500;
  elems[2].name = 2;
  elems[2].NameOfItem = 'knife';
  int *a = new int[3];
  a[0] = 0;
  a[1] = 0;
  a[2] = 0;
  int TestArr[3] = {0, 1, 0};
  findAns(A, 2, 4, elems, a);
  for (int i = 0; i < 3; i++) {
    if (a[i] != TestArr[i]) {
      flag = false;
    }
  }
  ASSERT_EQ(flag, true);
}

