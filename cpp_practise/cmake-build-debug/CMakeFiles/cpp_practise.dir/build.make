# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/markyoung/Desktop/ClionProjects/cpp_practise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp_practise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp_practise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_practise.dir/flags.make

CMakeFiles/cpp_practise.dir/main.cpp.o: CMakeFiles/cpp_practise.dir/flags.make
CMakeFiles/cpp_practise.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp_practise.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_practise.dir/main.cpp.o -c /Users/markyoung/Desktop/ClionProjects/cpp_practise/main.cpp

CMakeFiles/cpp_practise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_practise.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/markyoung/Desktop/ClionProjects/cpp_practise/main.cpp > CMakeFiles/cpp_practise.dir/main.cpp.i

CMakeFiles/cpp_practise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_practise.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/markyoung/Desktop/ClionProjects/cpp_practise/main.cpp -o CMakeFiles/cpp_practise.dir/main.cpp.s

CMakeFiles/cpp_practise.dir/A.cpp.o: CMakeFiles/cpp_practise.dir/flags.make
CMakeFiles/cpp_practise.dir/A.cpp.o: ../A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp_practise.dir/A.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_practise.dir/A.cpp.o -c /Users/markyoung/Desktop/ClionProjects/cpp_practise/A.cpp

CMakeFiles/cpp_practise.dir/A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_practise.dir/A.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/markyoung/Desktop/ClionProjects/cpp_practise/A.cpp > CMakeFiles/cpp_practise.dir/A.cpp.i

CMakeFiles/cpp_practise.dir/A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_practise.dir/A.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/markyoung/Desktop/ClionProjects/cpp_practise/A.cpp -o CMakeFiles/cpp_practise.dir/A.cpp.s

# Object files for target cpp_practise
cpp_practise_OBJECTS = \
"CMakeFiles/cpp_practise.dir/main.cpp.o" \
"CMakeFiles/cpp_practise.dir/A.cpp.o"

# External object files for target cpp_practise
cpp_practise_EXTERNAL_OBJECTS =

cpp_practise: CMakeFiles/cpp_practise.dir/main.cpp.o
cpp_practise: CMakeFiles/cpp_practise.dir/A.cpp.o
cpp_practise: CMakeFiles/cpp_practise.dir/build.make
cpp_practise: CMakeFiles/cpp_practise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpp_practise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_practise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_practise.dir/build: cpp_practise

.PHONY : CMakeFiles/cpp_practise.dir/build

CMakeFiles/cpp_practise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_practise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_practise.dir/clean

CMakeFiles/cpp_practise.dir/depend:
	cd /Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/markyoung/Desktop/ClionProjects/cpp_practise /Users/markyoung/Desktop/ClionProjects/cpp_practise /Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug /Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug /Users/markyoung/Desktop/ClionProjects/cpp_practise/cmake-build-debug/CMakeFiles/cpp_practise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp_practise.dir/depend
