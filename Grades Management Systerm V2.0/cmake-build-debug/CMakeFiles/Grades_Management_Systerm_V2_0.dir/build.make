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
CMAKE_SOURCE_DIR = "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Grades_Management_Systerm_V2_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Grades_Management_Systerm_V2_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Grades_Management_Systerm_V2_0.dir/flags.make

CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.o: CMakeFiles/Grades_Management_Systerm_V2_0.dir/flags.make
CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.o   -c "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/main.c"

CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/main.c" > CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.i

CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/main.c" -o CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.s

# Object files for target Grades_Management_Systerm_V2_0
Grades_Management_Systerm_V2_0_OBJECTS = \
"CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.o"

# External object files for target Grades_Management_Systerm_V2_0
Grades_Management_Systerm_V2_0_EXTERNAL_OBJECTS =

Grades_Management_Systerm_V2_0: CMakeFiles/Grades_Management_Systerm_V2_0.dir/main.c.o
Grades_Management_Systerm_V2_0: CMakeFiles/Grades_Management_Systerm_V2_0.dir/build.make
Grades_Management_Systerm_V2_0: CMakeFiles/Grades_Management_Systerm_V2_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Grades_Management_Systerm_V2_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Grades_Management_Systerm_V2_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Grades_Management_Systerm_V2_0.dir/build: Grades_Management_Systerm_V2_0

.PHONY : CMakeFiles/Grades_Management_Systerm_V2_0.dir/build

CMakeFiles/Grades_Management_Systerm_V2_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Grades_Management_Systerm_V2_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Grades_Management_Systerm_V2_0.dir/clean

CMakeFiles/Grades_Management_Systerm_V2_0.dir/depend:
	cd "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0" "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0" "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug" "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug" "/Users/markyoung/Desktop/ClionProjects/Grades Management Systerm V2.0/cmake-build-debug/CMakeFiles/Grades_Management_Systerm_V2_0.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Grades_Management_Systerm_V2_0.dir/depend

