# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caizh/CPlusLearning_Caizh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caizh/CPlusLearning_Caizh

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/Source/main.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Source/main.cpp.o: Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caizh/CPlusLearning_Caizh/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/Source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Source/main.cpp.o -c /home/caizh/CPlusLearning_Caizh/Source/main.cpp

CMakeFiles/demo.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caizh/CPlusLearning_Caizh/Source/main.cpp > CMakeFiles/demo.dir/Source/main.cpp.i

CMakeFiles/demo.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caizh/CPlusLearning_Caizh/Source/main.cpp -o CMakeFiles/demo.dir/Source/main.cpp.s

CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.o: Source/LeetCodeSolution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caizh/CPlusLearning_Caizh/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.o -c /home/caizh/CPlusLearning_Caizh/Source/LeetCodeSolution.cpp

CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caizh/CPlusLearning_Caizh/Source/LeetCodeSolution.cpp > CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.i

CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caizh/CPlusLearning_Caizh/Source/LeetCodeSolution.cpp -o CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.s

CMakeFiles/demo.dir/Source/mathFcn.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Source/mathFcn.cpp.o: Source/mathFcn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caizh/CPlusLearning_Caizh/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/demo.dir/Source/mathFcn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Source/mathFcn.cpp.o -c /home/caizh/CPlusLearning_Caizh/Source/mathFcn.cpp

CMakeFiles/demo.dir/Source/mathFcn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Source/mathFcn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caizh/CPlusLearning_Caizh/Source/mathFcn.cpp > CMakeFiles/demo.dir/Source/mathFcn.cpp.i

CMakeFiles/demo.dir/Source/mathFcn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Source/mathFcn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caizh/CPlusLearning_Caizh/Source/mathFcn.cpp -o CMakeFiles/demo.dir/Source/mathFcn.cpp.s

CMakeFiles/demo.dir/Source/testFcns.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Source/testFcns.cpp.o: Source/testFcns.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caizh/CPlusLearning_Caizh/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/demo.dir/Source/testFcns.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Source/testFcns.cpp.o -c /home/caizh/CPlusLearning_Caizh/Source/testFcns.cpp

CMakeFiles/demo.dir/Source/testFcns.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Source/testFcns.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caizh/CPlusLearning_Caizh/Source/testFcns.cpp > CMakeFiles/demo.dir/Source/testFcns.cpp.i

CMakeFiles/demo.dir/Source/testFcns.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Source/testFcns.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caizh/CPlusLearning_Caizh/Source/testFcns.cpp -o CMakeFiles/demo.dir/Source/testFcns.cpp.s

CMakeFiles/demo.dir/Source/nQueen.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Source/nQueen.cpp.o: Source/nQueen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caizh/CPlusLearning_Caizh/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/demo.dir/Source/nQueen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Source/nQueen.cpp.o -c /home/caizh/CPlusLearning_Caizh/Source/nQueen.cpp

CMakeFiles/demo.dir/Source/nQueen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Source/nQueen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caizh/CPlusLearning_Caizh/Source/nQueen.cpp > CMakeFiles/demo.dir/Source/nQueen.cpp.i

CMakeFiles/demo.dir/Source/nQueen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Source/nQueen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caizh/CPlusLearning_Caizh/Source/nQueen.cpp -o CMakeFiles/demo.dir/Source/nQueen.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/Source/main.cpp.o" \
"CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.o" \
"CMakeFiles/demo.dir/Source/mathFcn.cpp.o" \
"CMakeFiles/demo.dir/Source/testFcns.cpp.o" \
"CMakeFiles/demo.dir/Source/nQueen.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/Source/main.cpp.o
demo: CMakeFiles/demo.dir/Source/LeetCodeSolution.cpp.o
demo: CMakeFiles/demo.dir/Source/mathFcn.cpp.o
demo: CMakeFiles/demo.dir/Source/testFcns.cpp.o
demo: CMakeFiles/demo.dir/Source/nQueen.cpp.o
demo: CMakeFiles/demo.dir/build.make
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caizh/CPlusLearning_Caizh/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo

.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/caizh/CPlusLearning_Caizh && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caizh/CPlusLearning_Caizh /home/caizh/CPlusLearning_Caizh /home/caizh/CPlusLearning_Caizh /home/caizh/CPlusLearning_Caizh /home/caizh/CPlusLearning_Caizh/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend

