# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/homuwell/github/Algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/homuwell/github/Algorithms/build

# Include any dependencies generated for this target.
include CMakeFiles/S1L2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/S1L2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/S1L2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/S1L2.dir/flags.make

CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o: CMakeFiles/S1L2.dir/flags.make
CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o: /home/homuwell/github/Algorithms/1sem/lab2/main.cpp
CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o: CMakeFiles/S1L2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/homuwell/github/Algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o -MF CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o.d -o CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o -c /home/homuwell/github/Algorithms/1sem/lab2/main.cpp

CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/homuwell/github/Algorithms/1sem/lab2/main.cpp > CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.i

CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/homuwell/github/Algorithms/1sem/lab2/main.cpp -o CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.s

CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o: CMakeFiles/S1L2.dir/flags.make
CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o: /home/homuwell/github/Algorithms/1sem/lab2/tests/testStack.cpp
CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o: CMakeFiles/S1L2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/homuwell/github/Algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o -MF CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o.d -o CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o -c /home/homuwell/github/Algorithms/1sem/lab2/tests/testStack.cpp

CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/homuwell/github/Algorithms/1sem/lab2/tests/testStack.cpp > CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.i

CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/homuwell/github/Algorithms/1sem/lab2/tests/testStack.cpp -o CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.s

# Object files for target S1L2
S1L2_OBJECTS = \
"CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o" \
"CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o"

# External object files for target S1L2
S1L2_EXTERNAL_OBJECTS =

S1L2: CMakeFiles/S1L2.dir/1sem/lab2/main.cpp.o
S1L2: CMakeFiles/S1L2.dir/1sem/lab2/tests/testStack.cpp.o
S1L2: CMakeFiles/S1L2.dir/build.make
S1L2: lib/libgtest.a
S1L2: lib/libgtest_main.a
S1L2: lib/libgtest.a
S1L2: CMakeFiles/S1L2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/homuwell/github/Algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable S1L2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/S1L2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/S1L2.dir/build: S1L2
.PHONY : CMakeFiles/S1L2.dir/build

CMakeFiles/S1L2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/S1L2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/S1L2.dir/clean

CMakeFiles/S1L2.dir/depend:
	cd /home/homuwell/github/Algorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/homuwell/github/Algorithms /home/homuwell/github/Algorithms /home/homuwell/github/Algorithms/build /home/homuwell/github/Algorithms/build /home/homuwell/github/Algorithms/build/CMakeFiles/S1L2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/S1L2.dir/depend

