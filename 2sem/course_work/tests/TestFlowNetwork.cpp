#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/FlowNetwork.h"
#include <fstream>
using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  FlowNetwork obj;
  ClassDeclaration() {
    obj;
  }
};
}

TEST_F(ClassDeclaration, FileWithOutSource) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "Z O 3\n"
             "Z P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Q T 2\n"
             "R T 3";
  in << s;
  in.close();
  try {
    obj.read_network();
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Source aren't marked");
  }
}
TEST_F(ClassDeclaration, FordFulkersonExample) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Q T 2\n"
             "R T 3";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(5, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkersonCormen) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string network = "S O 16\n"
                   "S P 13\n"
                   "O Q 12\n"
                   "Q P 9\n"
                   "P O 4\n"
                   "P L 14\n"
                   "P Q 7\n"
                   "Q T 20\n"
                   "L T 4";
  in << network;
  in.close();
  obj.read_network();
  ASSERT_EQ(23, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkersonNoWay) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Z T 3";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(0, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, Add) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Z T 3";
  in << s;
  in.close();
  obj.read_network();
  obj.add(3, 6, 2);
  obj.add(4, 6, 3);
  ASSERT_EQ(5, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, BFSCorrect) {
  size_t arr[6][6] = {{0, 3, 3, 0, 0, 0},
                      {0, 0, 2, 3, 0, 0},
                      {0, 0, 0, 0, 2, 0},
                      {0, 0, 0, 0, 4, 2},
                      {0, 0, 0, 0, 0, 3},
                      {0, 0, 0, 0, 0, 0}};
  size_t fun[6];
  obj.set_size(6);
  obj.set_sink(5);
  obj.set_source(0);
  ASSERT_EQ(obj.BFS(*arr, fun), true);
}

TEST_F(ClassDeclaration, BFSWrong) {
  size_t arr[6][6] = {{0, 3, 3, 0, 0, 0},
                      {0, 0, 2, 3, 0, 0},
                      {0, 0, 0, 0, 2, 0},
                      {0, 0, 0, 0, 4, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}};
  size_t fun[6];
  obj.set_size(6);
  obj.set_sink(5);
  obj.set_source(0);
  ASSERT_EQ(obj.BFS(*arr, fun), false);
}
TEST_F(ClassDeclaration, FileWithOutSink) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Q Z 2\n"
             "R Z 3";
  in << s;
  in.close();
  try {
    obj.read_network();
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Sink aren't marked");
  }
}

TEST_F(ClassDeclaration, SizeBiggerMax) {
  try {
    obj.set_size(100000);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Size can't be more than max size");
  }
}

TEST_F(ClassDeclaration, CorrectSetSize) {
  obj.set_size(50);
  ASSERT_EQ(obj.get_size(), 50);
}

TEST_F(ClassDeclaration, SizeLowerCurrent) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Z T 3";
  in << s;
  in.close();
  obj.read_network();
  try {
    obj.set_size(2);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Size can't be less than current");
  }
}

TEST_F(ClassDeclaration, WrongSetSink) {
  try {
    obj.set_sink(100000);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Sink out of matrix");
  }
}

TEST_F(ClassDeclaration, CorrectSetSink) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\n"
             "Z T 3";
  in << s;
  in.close();
  obj.read_network();
  obj.set_sink(2);
  ASSERT_EQ(obj.get_sink(), 2);
}

TEST_F(ClassDeclaration, WrongSetSource) {
  try {
    obj.set_source(100000);
    FAIL();
  }
  catch (const invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Source out of matrix");
  }
}

TEST_F(ClassDeclaration, CorrectSetsource) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 3\n"
             "S P 3\n"
             "O Q 3\n"
             "O P 2\n"
             "P R 2\n"
             "Q R 4\nZ T 3";
  in << s;
  in.close();
  obj.read_network();
  obj.set_source(2);
  ASSERT_EQ(obj.get_source(), 2);
}

TEST_F(ClassDeclaration, FordFulkerson1) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S 2 10\n"
             "S 3 7\n"
             "2 5 3\n"
             "2 4 9\n"
             "3 4 11\n"
             "3 6 2\n"
             "5 7 4\n"
             "4 7 8\n"
             "4 8 12\n"
             "4 9 1\n"
             "6 9 5\n"
             "7 T 6\n"
             "8 T 13\n"
             "9 T 8";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(17, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkerson2) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S 2 3\n"
             "S 3 4\n"
             "S 4 2\n"
             "2 5 3\n"
             "3 5 6\n"
             "4 5 3\n"
             "4 6 1\n"
             "5 7 8\n"
             "5 9 7\n"
             "5 6 1\n"
             "6 7 6\n"
             "7 T 14\n"
             "6 8 12\n"
             "8 T 11\n"
             "8 9 6\n"
             "9 T 3";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(9, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkerson3) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 100\n"
             "S P 200\n"
             "O Z 150\n"
             "P Z 100\n"
             "Z K 100\n"
             "Z R 300\n"
             "Z T 50\n"
             "K X 50\n"
             "X T 30\n"
             "R Y 250\n"
             "Y T 100";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(180, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkerson4) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 100\n"
             "S P 200\n"
             "O Z 100\n"
             "P Z 100\n"
             "Z K 500\n"
             "K X 80\n"
             "X T 53\n"
             "Z R 350\n"
             "R Y 50\n"
             "Y T 105";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(103, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkerson5) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 100\n"
             "S P 200\n"
             "O P 50\n"
             "O R 100\n"
             "R X 1\n"
             "R Z 30\n"
             "X T 100\n"
             "Z T 10\n"
             "P K 150\n"
             "P O 45\n"
             "K Z 10\n"
             "K Y 1\n"
             "Y T 100";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(12, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkerson6) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 100\n"
             "S P 200\n"
             "O P 50\n"
             "O R 100\n"
             "R X 95\n"
             "R Z 50\n"
             "X T 100\n"
             "Z T 300\n"
             "P K 150\n"
             "P O 45\n"
             "K Z 85\n"
             "K Y 50\n"
             "Y T 100";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(235, obj.Ford_Fulkerson());
}
TEST_F(ClassDeclaration, FordFulkerson7) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/course_work/in", ios::out);
  string s = "S O 100\n"
             "S P 200\n"
             "O P 50\n"
             "O R 100\n"
             "R X 95\n"
             "R Z 50\n"
             "X T 50\n"
             "Z T 100\n"
             "P K 150\n"
             "P O 45\n"
             "K Z 85\n"
             "K Y 50\n"
             "Y T 60";
  in << s;
  in.close();
  obj.read_network();
  ASSERT_EQ(200, obj.Ford_Fulkerson());
}
