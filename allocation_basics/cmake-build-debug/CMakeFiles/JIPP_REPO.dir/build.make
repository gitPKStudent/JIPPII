# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/JIPP_REPO.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/JIPP_REPO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JIPP_REPO.dir/flags.make

CMakeFiles/JIPP_REPO.dir/main.cpp.o: CMakeFiles/JIPP_REPO.dir/flags.make
CMakeFiles/JIPP_REPO.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JIPP_REPO.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JIPP_REPO.dir/main.cpp.o -c /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/main.cpp

CMakeFiles/JIPP_REPO.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JIPP_REPO.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/main.cpp > CMakeFiles/JIPP_REPO.dir/main.cpp.i

CMakeFiles/JIPP_REPO.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JIPP_REPO.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/main.cpp -o CMakeFiles/JIPP_REPO.dir/main.cpp.s

# Object files for target JIPP_REPO
JIPP_REPO_OBJECTS = \
"CMakeFiles/JIPP_REPO.dir/main.cpp.o"

# External object files for target JIPP_REPO
JIPP_REPO_EXTERNAL_OBJECTS =

JIPP_REPO: CMakeFiles/JIPP_REPO.dir/main.cpp.o
JIPP_REPO: CMakeFiles/JIPP_REPO.dir/build.make
JIPP_REPO: CMakeFiles/JIPP_REPO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JIPP_REPO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JIPP_REPO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JIPP_REPO.dir/build: JIPP_REPO
.PHONY : CMakeFiles/JIPP_REPO.dir/build

CMakeFiles/JIPP_REPO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JIPP_REPO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JIPP_REPO.dir/clean

CMakeFiles/JIPP_REPO.dir/depend:
	cd /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug /home/nicolaus/PK2020-2024/SIII/JIPP/JIPP_REPO/allocation_basics/cmake-build-debug/CMakeFiles/JIPP_REPO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JIPP_REPO.dir/depend

