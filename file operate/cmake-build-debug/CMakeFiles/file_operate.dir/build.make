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
CMAKE_SOURCE_DIR = "/Users/markyoung/Desktop/ClionProjects/file operate"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/file_operate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/file_operate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/file_operate.dir/flags.make

CMakeFiles/file_operate.dir/main.c.o: CMakeFiles/file_operate.dir/flags.make
CMakeFiles/file_operate.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/file_operate.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/file_operate.dir/main.c.o   -c "/Users/markyoung/Desktop/ClionProjects/file operate/main.c"

CMakeFiles/file_operate.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/file_operate.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/markyoung/Desktop/ClionProjects/file operate/main.c" > CMakeFiles/file_operate.dir/main.c.i

CMakeFiles/file_operate.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/file_operate.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/markyoung/Desktop/ClionProjects/file operate/main.c" -o CMakeFiles/file_operate.dir/main.c.s

# Object files for target file_operate
file_operate_OBJECTS = \
"CMakeFiles/file_operate.dir/main.c.o"

# External object files for target file_operate
file_operate_EXTERNAL_OBJECTS =

file_operate: CMakeFiles/file_operate.dir/main.c.o
file_operate: CMakeFiles/file_operate.dir/build.make
file_operate: CMakeFiles/file_operate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable file_operate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/file_operate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/file_operate.dir/build: file_operate

.PHONY : CMakeFiles/file_operate.dir/build

CMakeFiles/file_operate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/file_operate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/file_operate.dir/clean

CMakeFiles/file_operate.dir/depend:
	cd "/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/markyoung/Desktop/ClionProjects/file operate" "/Users/markyoung/Desktop/ClionProjects/file operate" "/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug" "/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug" "/Users/markyoung/Desktop/ClionProjects/file operate/cmake-build-debug/CMakeFiles/file_operate.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/file_operate.dir/depend

