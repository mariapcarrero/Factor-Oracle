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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestFOS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestFOS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestFOS.dir/flags.make

CMakeFiles/TestFOS.dir/test_fos.cpp.o: CMakeFiles/TestFOS.dir/flags.make
CMakeFiles/TestFOS.dir/test_fos.cpp.o: ../test_fos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestFOS.dir/test_fos.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestFOS.dir/test_fos.cpp.o -c /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/test_fos.cpp

CMakeFiles/TestFOS.dir/test_fos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestFOS.dir/test_fos.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/test_fos.cpp > CMakeFiles/TestFOS.dir/test_fos.cpp.i

CMakeFiles/TestFOS.dir/test_fos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestFOS.dir/test_fos.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/test_fos.cpp -o CMakeFiles/TestFOS.dir/test_fos.cpp.s

# Object files for target TestFOS
TestFOS_OBJECTS = \
"CMakeFiles/TestFOS.dir/test_fos.cpp.o"

# External object files for target TestFOS
TestFOS_EXTERNAL_OBJECTS =

TestFOS: CMakeFiles/TestFOS.dir/test_fos.cpp.o
TestFOS: CMakeFiles/TestFOS.dir/build.make
TestFOS: libFO.a
TestFOS: CMakeFiles/TestFOS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestFOS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestFOS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestFOS.dir/build: TestFOS

.PHONY : CMakeFiles/TestFOS.dir/build

CMakeFiles/TestFOS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestFOS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestFOS.dir/clean

CMakeFiles/TestFOS.dir/depend:
	cd /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug/CMakeFiles/TestFOS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestFOS.dir/depend

