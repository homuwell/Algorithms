#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../algs.cpp"

using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  ClassDeclaration() {
  }
};
}
TEST_F(ClassDeclaration, run) { //empty stack
  //testQuickSort();
  //testInsertSort();
  ASSERT_EQ(true, true);
}
TEST_F(ClassDeclaration, testBinarySearch1) {
  int sort_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(binary_search(sort_arr, 10, 4), true);
}
TEST_F(ClassDeclaration, testBinarySearch2) {
  int sort_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(binary_search(sort_arr, 10, 22), false);
}
TEST_F(ClassDeclaration, testQuickSort) { //empty stack
  int test_arr[10] = {7, 9, 5, 2, 1, 4, 0, 3, 6, 8};
  int sort_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  qsortRecursive(test_arr, 10);
  ASSERT_EQ(cheak_arr(test_arr, sort_arr, 10), true);
}
TEST_F(ClassDeclaration, testInsertSort) { //empty stack
  int test_arr[10] = {7, 9, 5, 2, 1, 4, 0, 3, 6, 8};
  int sort_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  insert_sort(test_arr, 10);
  ASSERT_EQ(cheak_arr(test_arr, sort_arr, 10), true);
}
TEST_F(ClassDeclaration, testBinaryTreeSort) { //empty stack
  int test_arr[10] = {7, 9, 5, 2, 1, 4, 0, 3, 6, 8};
  int sort_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  BinaryTreeSort(test_arr, 10);
  ASSERT_EQ(cheak_arr(test_arr, sort_arr, 10), true);
}
TEST_F(ClassDeclaration, testBogoSort) { //empty stack
  int test_arr[5] = {3, 1, 0, 4, 2};
  int sort_arr[5] = {0, 1, 2, 3, 4};
  bogosort(test_arr, 5);
  ASSERT_EQ(cheak_arr(test_arr, sort_arr, 5), true);
}
TEST_F(ClassDeclaration, testCountsort) { //empty stack
  char test_arr[10] = {'f', 'a', 'f', 'b', 'b', 'a', 'f', 'c', 'a', 'c'};
  char sort_arr[10] = {'a', 'a', 'a', 'b', 'b', 'c', 'c', 'f', 'f', 'f'};
  CountingSort(test_arr, 10);
  ASSERT_EQ(cheak_arr(test_arr, sort_arr, 10), true);
}
