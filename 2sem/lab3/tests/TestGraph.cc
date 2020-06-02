#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/Graph.h"
#include <fstream>
using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  Graph obj;
  ClassDeclaration() {
    obj;
  }
};
}
TEST_F(ClassDeclaration, DijkstraAjacentElement) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/lab3/in", ios::out);
  string s = "Saint-Petersburg;Moscow;10;10\n"
             "Moscow;Cherepovets;40;35\n"
             "Saint-Petersburg;Cherepovets;14;N/A\n"
             "Vologda;Cherepovets;13;8\n"
             "Vologda;Saint-Petersburg;N/A;20";
  in << s;
  in.close();
  obj.input_cites();
  ASSERT_EQ(obj.create_route("Saint-Petersburg", "Vologda"), 20);
}

TEST_F(ClassDeclaration, DijkstraNoWay) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/lab3/in", ios::out);
  string s = "Saint-Petersburg;Moscow;50;10\n"
             "Vologda;Cherepovets;30;N/A";
  in << s;
  size_t a = -1;
  in.close();
  obj.input_cites();
  ASSERT_EQ(obj.create_route("Saint-Petersburg", "Vologda"), a);
}

TEST_F(ClassDeclaration, DijkstraBigGraph) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/lab3/in", ios::out);
  string s = "London;New-York;10;N/A\n"
             "London;Berlin;8;N/A\n"
             "London;Paris;6;N/A\n"
             "New-York;Berlin;5;N/A\n"
             "New-York;Oslo;11;N/A\n"
             "New-York;Dallas;13;N/A\n"
             "Paris;Dallas;3;N/A\n"
             "Berlin;Paris;2;N/A\n"
             "Berlin;Dallas;5;N/A\n"
             "Berlin;Dublin;7;N/A\n"
             "Berlin;Oslo;12;N/A\n"
             "Dallas;Dublin;9;N/A\n"
             "Dallas;Detroit;12;N/A\n"
             "Dublin;Vienna;8;N/A\n"
             "Dublin;Detroit;10;N/A\n"
             "Oslo;Dublin;4;N/A\n"
             "Oslo;Vienna;6;N/A\n"
             "Oslo;Detroit;16;N/A\n"
             "Vienna;Detroit;15;N/A";
  in << s;
  size_t a = -1;
  in.close();
  obj.input_cites();
  ASSERT_EQ(obj.create_route("London", "Oslo"), 20);
}

TEST_F(ClassDeclaration, DijkstraBigGraphNoWay) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/lab3/in", ios::out);
  string s = "London;New-York;10;N/A\n"
             "London;Berlin;8;N/A\n"
             "London;Paris;6;N/A\n"
             "New-York;Berlin;5;N/A\n"
             "New-York;Oslo;11;N/A\n"
             "New-York;Dallas;13;N/A\n"
             "Paris;Dallas;3;N/A\n"
             "Berlin;Paris;2;N/A\n"
             "Berlin;Dallas;5;N/A\n"
             "Berlin;Dublin;7;N/A\n"
             "Berlin;Oslo;12;N/A\n"
             "Dallas;Dublin;9;N/A\n"
             "Dallas;Detroit;12;N/A\n"
             "Dublin;Vienna;8;N/A\n"
             "Dublin;Detroit;10;N/A\n"
             "Oslo;Dublin;4;N/A\n"
             "Oslo;Vienna;6;N/A\n"
             "Oslo;Detroit;16;N/A\n"
             "Vienna;Detroit;15;N/A";
  in << s;
  size_t a = -1;
  in.close();
  obj.input_cites();
  ASSERT_EQ(obj.create_route("Detroit", "London"), a);
}

TEST_F(ClassDeclaration, DijkstraBigGraphDifficltWay) {
  fstream in;
  in.open("/home/homuwell/CLionProjects/algorithms/2sem/lab3/in", ios::out);
  string s = "London;New-York;10;N/A\n"
             "London;Berlin;8;N/A\n"
             "London;Paris;6;N/A\n"
             "New-York;Berlin;5;N/A\n"
             "New-York;Oslo;11;N/A\n"
             "New-York;Dallas;13;N/A\n"
             "Paris;Dallas;3;N/A\n"
             "Berlin;Paris;2;N/A\n"
             "Berlin;Dallas;5;N/A\n"
             "Berlin;Dublin;7;N/A\n"
             "Berlin;Oslo;12;N/A\n"
             "Dallas;Dublin;9;N/A\n"
             "Dallas;Detroit;12;N/A\n"
             "Dublin;Vienna;8;N/A\n"
             "Dublin;Detroit;10;N/A\n"
             "Oslo;Dublin;4;N/A\n"
             "Oslo;Vienna;6;N/A\n"
             "Oslo;Detroit;16;N/A\n"
             "Vienna;Detroit;15;N/A";
  in << s;
  size_t a = -1;
  in.close();
  obj.input_cites();
  ASSERT_EQ(obj.create_route("London", "Vienna"), 23);
}

TEST_F(ClassDeclaration, DijkstraAddWithoutEdges) {
  bool flag = true;
  obj.add_vertex("Las-Vegas", "Washington", -1, -1);
  if (obj.find("Las-Vegas")->edges_.head_ != nullptr && obj.find("Washington")->edges_.head_ != nullptr) {
    flag = false;
  }
  ASSERT_EQ(flag, true);
}

TEST_F(ClassDeclaration, DijkstraAddOneEdge) {
  bool flag = true;
  obj.add_vertex("Las-Vegas", "Washington", 5, -1);
  if (obj.find("Las-Vegas")->edges_.head_ == nullptr && obj.find("Washington")->edges_.head_ != nullptr) {
    flag = false;
  }
  ASSERT_EQ(flag, true);
}

TEST_F(ClassDeclaration, DijkstraAddTwoEdges) {
  bool flag = true;
  obj.add_vertex("Las-Vegas", "Washington", 5, 20);
  if (obj.find("Las-Vegas")->edges_.head_ == nullptr || obj.find("Washington")->edges_.head_ == nullptr) {
    flag = false;
  }
  ASSERT_EQ(flag, true);
}

TEST_F(ClassDeclaration, AddEdge) {
  bool flag = true;
  obj.add_vertex("Las-Vegas", "Washington", -1, -1);
  obj.find("Las-Vegas")->edges_.push_back(40, obj.find("Washington"));
  if (obj.find("Las-Vegas")->edges_.head_->weight_ != 40) {
    flag = false;
  }
  ASSERT_EQ(flag, true);
}



