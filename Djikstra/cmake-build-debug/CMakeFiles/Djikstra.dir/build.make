# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/markyoung/Desktop/ClionProjects/Djikstra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Djikstra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Djikstra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Djikstra.dir/flags.make

CMakeFiles/Djikstra.dir/main.c.o: CMakeFiles/Djikstra.dir/flags.make
CMakeFiles/Djikstra.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Djikstra.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Djikstra.dir/main.c.o   -c /Users/markyoung/Desktop/ClionProjects/Djikstra/main.c

CMakeFiles/Djikstra.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Djikstra.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/markyoung/Desktop/ClionProjects/Djikstra/main.c > CMakeFiles/Djikstra.dir/main.c.i

CMakeFiles/Djikstra.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Djikstra.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/markyoung/Desktop/ClionProjects/Djikstra/main.c -o CMakeFiles/Djikstra.dir/main.c.s

# Object files for target Djikstra
Djikstra_OBJECTS = \
"CMakeFiles/Djikstra.dir/main.c.o"

# External object files for target Djikstra
Djikstra_EXTERNAL_OBJECTS =

Djikstra: CMakeFiles/Djikstra.dir/main.c.o
Djikstra: CMakeFiles/Djikstra.dir/build.make
Djikstra: CMakeFiles/Djikstra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Djikstra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Djikstra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Djikstra.dir/build: Djikstra

.PHONY : CMakeFiles/Djikstra.dir/build

CMakeFiles/Djikstra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Djikstra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Djikstra.dir/clean

CMakeFiles/Djikstra.dir/depend:
	cd /Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/markyoung/Desktop/ClionProjects/Djikstra /Users/markyoung/Desktop/ClionProjects/Djikstra /Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug /Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug /Users/markyoung/Desktop/ClionProjects/Djikstra/cmake-build-debug/CMakeFiles/Djikstra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Djikstra.dir/depend

