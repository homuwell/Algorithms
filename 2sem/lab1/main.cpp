#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "headers/map.h";
using namespace std;
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  Map<int, string> obj;
  obj.insert(5, "car");
  obj.insert(4, "chair");
  obj.insert(8, "bed");
  obj.insert(10, "chair");
  obj.insert(7, "bed");
  obj.print();
  return 0;
}
