#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "headers/List.h"
int main(int argc, char **argv) {
  /*List main;
  List main1;
  int value;
  main.push_back(5);
  main.push_back(10);
  main.push_back(15);
  main.push_back(20);
  main.push_back(25);
  main.push_back(30);
  main1.push_back(15);
  main1.push_back(20);
  main1.push_back(25);
  value = main.find_first(main1);
  cout << value;*/
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;

}
