cmake_minimum_required(VERSION 3.15)
project(algorithms)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)
add_executable(S1L1 1sem/lab1/main.cpp 1sem/lab1/classes/List.cpp 1sem/lab1/tests/testList.cpp)
add_executable(S1L2 1sem/lab2/main.cpp 1sem/lab2/headers/Stack.h 1sem/lab2/tests/testStack.cpp)
add_executable(S1L3 1sem/lab3/main.cpp 1sem/lab3/classes/Tree.cpp 1sem/lab3/tests/testTree.cpp 1sem/lab3/headers/Iterator.h)
add_executable(S1L4 1sem/lab4/main.cpp 1sem/lab3/classes/Tree.cpp 1sem/lab4/tests/testAlgs.cpp)
add_executable(S1CW 1sem/course_work/main.cpp 1sem/course_work/tests/tests.cpp)
add_executable(S2L1 2sem/lab1/main.cpp 2sem/lab1/headers/map.h 2sem/lab1/tests/testMap.cpp)
add_executable(S2L2 2sem/lab2/main.cpp 2sem/lab2/classes/SymbolsList.cc 2sem/lab2/classes/ShannonFano.cc 2sem/lab2/classes/SFTree.cc 2sem/lab2/tests/TestShanonFano.cc)
add_executable(S2L3 2sem/lab3/main.cpp 2sem/lab3/classes/Graph.cc 2sem/lab3/classes/Edges.cc 2sem/lab3/tests/TestGraph.cc)
add_executable(S2CW 2sem/course_work/main.cpp 2sem/course_work/classes/FlowNetwork.cc 2sem/course_work/headers/Queue.h 2sem/course_work/tests/TestFlowNetwork.cpp)
target_link_libraries(S1CW gtest gtest_main)
target_link_libraries(S1L1 gtest gtest_main)
target_link_libraries(S1L2 gtest gtest_main)
target_link_libraries(S1L3 gtest gtest_main)
target_link_libraries(S1L4 gtest gtest_main)
target_link_libraries(S2L1 gtest gtest_main)
target_link_libraries(S2CW gtest gtest_main)
target_link_libraries(S2L2 gtest gtest_main)
target_link_libraries(S2L3 gtest gtest_main)

