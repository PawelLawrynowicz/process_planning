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
CMAKE_SOURCE_DIR = /home/pwl/Documents/nokia_homework1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pwl/Documents/nokia_homework1/build

# Include any dependencies generated for this target.
include CMakeFiles/nokia_homework1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nokia_homework1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nokia_homework1.dir/flags.make

CMakeFiles/nokia_homework1.dir/OS_Project.cpp.o: CMakeFiles/nokia_homework1.dir/flags.make
CMakeFiles/nokia_homework1.dir/OS_Project.cpp.o: ../OS_Project.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pwl/Documents/nokia_homework1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nokia_homework1.dir/OS_Project.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nokia_homework1.dir/OS_Project.cpp.o -c /home/pwl/Documents/nokia_homework1/OS_Project.cpp

CMakeFiles/nokia_homework1.dir/OS_Project.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nokia_homework1.dir/OS_Project.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pwl/Documents/nokia_homework1/OS_Project.cpp > CMakeFiles/nokia_homework1.dir/OS_Project.cpp.i

CMakeFiles/nokia_homework1.dir/OS_Project.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nokia_homework1.dir/OS_Project.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pwl/Documents/nokia_homework1/OS_Project.cpp -o CMakeFiles/nokia_homework1.dir/OS_Project.cpp.s

CMakeFiles/nokia_homework1.dir/Process.cpp.o: CMakeFiles/nokia_homework1.dir/flags.make
CMakeFiles/nokia_homework1.dir/Process.cpp.o: ../Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pwl/Documents/nokia_homework1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/nokia_homework1.dir/Process.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nokia_homework1.dir/Process.cpp.o -c /home/pwl/Documents/nokia_homework1/Process.cpp

CMakeFiles/nokia_homework1.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nokia_homework1.dir/Process.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pwl/Documents/nokia_homework1/Process.cpp > CMakeFiles/nokia_homework1.dir/Process.cpp.i

CMakeFiles/nokia_homework1.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nokia_homework1.dir/Process.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pwl/Documents/nokia_homework1/Process.cpp -o CMakeFiles/nokia_homework1.dir/Process.cpp.s

# Object files for target nokia_homework1
nokia_homework1_OBJECTS = \
"CMakeFiles/nokia_homework1.dir/OS_Project.cpp.o" \
"CMakeFiles/nokia_homework1.dir/Process.cpp.o"

# External object files for target nokia_homework1
nokia_homework1_EXTERNAL_OBJECTS =

nokia_homework1: CMakeFiles/nokia_homework1.dir/OS_Project.cpp.o
nokia_homework1: CMakeFiles/nokia_homework1.dir/Process.cpp.o
nokia_homework1: CMakeFiles/nokia_homework1.dir/build.make
nokia_homework1: CMakeFiles/nokia_homework1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pwl/Documents/nokia_homework1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable nokia_homework1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nokia_homework1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nokia_homework1.dir/build: nokia_homework1

.PHONY : CMakeFiles/nokia_homework1.dir/build

CMakeFiles/nokia_homework1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nokia_homework1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nokia_homework1.dir/clean

CMakeFiles/nokia_homework1.dir/depend:
	cd /home/pwl/Documents/nokia_homework1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pwl/Documents/nokia_homework1 /home/pwl/Documents/nokia_homework1 /home/pwl/Documents/nokia_homework1/build /home/pwl/Documents/nokia_homework1/build /home/pwl/Documents/nokia_homework1/build/CMakeFiles/nokia_homework1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nokia_homework1.dir/depend

