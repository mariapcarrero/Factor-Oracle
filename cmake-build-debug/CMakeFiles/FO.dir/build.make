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
include CMakeFiles/FO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FO.dir/flags.make

CMakeFiles/FO.dir/FactorOracle.cpp.o: CMakeFiles/FO.dir/flags.make
CMakeFiles/FO.dir/FactorOracle.cpp.o: ../FactorOracle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FO.dir/FactorOracle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FO.dir/FactorOracle.cpp.o -c /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/FactorOracle.cpp

CMakeFiles/FO.dir/FactorOracle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FO.dir/FactorOracle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/FactorOracle.cpp > CMakeFiles/FO.dir/FactorOracle.cpp.i

CMakeFiles/FO.dir/FactorOracle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FO.dir/FactorOracle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/FactorOracle.cpp -o CMakeFiles/FO.dir/FactorOracle.cpp.s

# Object files for target FO
FO_OBJECTS = \
"CMakeFiles/FO.dir/FactorOracle.cpp.o"

# External object files for target FO
FO_EXTERNAL_OBJECTS =

libFO.a: CMakeFiles/FO.dir/FactorOracle.cpp.o
libFO.a: CMakeFiles/FO.dir/build.make
libFO.a: CMakeFiles/FO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libFO.a"
	$(CMAKE_COMMAND) -P CMakeFiles/FO.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FO.dir/build: libFO.a

.PHONY : CMakeFiles/FO.dir/build

CMakeFiles/FO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FO.dir/clean

CMakeFiles/FO.dir/depend:
	cd /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug /Users/mariapaulacarrero/Documents/GitHub/Factor-Oracle/cmake-build-debug/CMakeFiles/FO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FO.dir/depend

