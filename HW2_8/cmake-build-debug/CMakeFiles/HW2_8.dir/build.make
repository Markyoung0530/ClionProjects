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
CMAKE_SOURCE_DIR = /Users/markyoung/Desktop/ClionProjects/HW2_8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW2_8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW2_8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW2_8.dir/flags.make

CMakeFiles/HW2_8.dir/main.c.o: CMakeFiles/HW2_8.dir/flags.make
CMakeFiles/HW2_8.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HW2_8.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HW2_8.dir/main.c.o   -c /Users/markyoung/Desktop/ClionProjects/HW2_8/main.c

CMakeFiles/HW2_8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW2_8.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/markyoung/Desktop/ClionProjects/HW2_8/main.c > CMakeFiles/HW2_8.dir/main.c.i

CMakeFiles/HW2_8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW2_8.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/markyoung/Desktop/ClionProjects/HW2_8/main.c -o CMakeFiles/HW2_8.dir/main.c.s

# Object files for target HW2_8
HW2_8_OBJECTS = \
"CMakeFiles/HW2_8.dir/main.c.o"

# External object files for target HW2_8
HW2_8_EXTERNAL_OBJECTS =

HW2_8: CMakeFiles/HW2_8.dir/main.c.o
HW2_8: CMakeFiles/HW2_8.dir/build.make
HW2_8: CMakeFiles/HW2_8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable HW2_8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW2_8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW2_8.dir/build: HW2_8

.PHONY : CMakeFiles/HW2_8.dir/build

CMakeFiles/HW2_8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW2_8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW2_8.dir/clean

CMakeFiles/HW2_8.dir/depend:
	cd /Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/markyoung/Desktop/ClionProjects/HW2_8 /Users/markyoung/Desktop/ClionProjects/HW2_8 /Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug /Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug /Users/markyoung/Desktop/ClionProjects/HW2_8/cmake-build-debug/CMakeFiles/HW2_8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW2_8.dir/depend

