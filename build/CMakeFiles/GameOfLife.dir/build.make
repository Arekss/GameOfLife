# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/arek/advCPP/GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arek/advCPP/GameOfLife/build

# Include any dependencies generated for this target.
include CMakeFiles/GameOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameOfLife.dir/flags.make

CMakeFiles/GameOfLife.dir/main.cpp.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arek/advCPP/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameOfLife.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameOfLife.dir/main.cpp.o -c /home/arek/advCPP/GameOfLife/main.cpp

CMakeFiles/GameOfLife.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arek/advCPP/GameOfLife/main.cpp > CMakeFiles/GameOfLife.dir/main.cpp.i

CMakeFiles/GameOfLife.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arek/advCPP/GameOfLife/main.cpp -o CMakeFiles/GameOfLife.dir/main.cpp.s

CMakeFiles/GameOfLife.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/GameOfLife.dir/main.cpp.o.requires

CMakeFiles/GameOfLife.dir/main.cpp.o.provides: CMakeFiles/GameOfLife.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameOfLife.dir/build.make CMakeFiles/GameOfLife.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/GameOfLife.dir/main.cpp.o.provides

CMakeFiles/GameOfLife.dir/main.cpp.o.provides.build: CMakeFiles/GameOfLife.dir/main.cpp.o


CMakeFiles/GameOfLife.dir/src/Game.cpp.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arek/advCPP/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameOfLife.dir/src/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameOfLife.dir/src/Game.cpp.o -c /home/arek/advCPP/GameOfLife/src/Game.cpp

CMakeFiles/GameOfLife.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arek/advCPP/GameOfLife/src/Game.cpp > CMakeFiles/GameOfLife.dir/src/Game.cpp.i

CMakeFiles/GameOfLife.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arek/advCPP/GameOfLife/src/Game.cpp -o CMakeFiles/GameOfLife.dir/src/Game.cpp.s

CMakeFiles/GameOfLife.dir/src/Game.cpp.o.requires:

.PHONY : CMakeFiles/GameOfLife.dir/src/Game.cpp.o.requires

CMakeFiles/GameOfLife.dir/src/Game.cpp.o.provides: CMakeFiles/GameOfLife.dir/src/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameOfLife.dir/build.make CMakeFiles/GameOfLife.dir/src/Game.cpp.o.provides.build
.PHONY : CMakeFiles/GameOfLife.dir/src/Game.cpp.o.provides

CMakeFiles/GameOfLife.dir/src/Game.cpp.o.provides.build: CMakeFiles/GameOfLife.dir/src/Game.cpp.o


# Object files for target GameOfLife
GameOfLife_OBJECTS = \
"CMakeFiles/GameOfLife.dir/main.cpp.o" \
"CMakeFiles/GameOfLife.dir/src/Game.cpp.o"

# External object files for target GameOfLife
GameOfLife_EXTERNAL_OBJECTS =

GameOfLife: CMakeFiles/GameOfLife.dir/main.cpp.o
GameOfLife: CMakeFiles/GameOfLife.dir/src/Game.cpp.o
GameOfLife: CMakeFiles/GameOfLife.dir/build.make
GameOfLife: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
GameOfLife: CMakeFiles/GameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arek/advCPP/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GameOfLife"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameOfLife.dir/build: GameOfLife

.PHONY : CMakeFiles/GameOfLife.dir/build

CMakeFiles/GameOfLife.dir/requires: CMakeFiles/GameOfLife.dir/main.cpp.o.requires
CMakeFiles/GameOfLife.dir/requires: CMakeFiles/GameOfLife.dir/src/Game.cpp.o.requires

.PHONY : CMakeFiles/GameOfLife.dir/requires

CMakeFiles/GameOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameOfLife.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameOfLife.dir/clean

CMakeFiles/GameOfLife.dir/depend:
	cd /home/arek/advCPP/GameOfLife/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arek/advCPP/GameOfLife /home/arek/advCPP/GameOfLife /home/arek/advCPP/GameOfLife/build /home/arek/advCPP/GameOfLife/build /home/arek/advCPP/GameOfLife/build/CMakeFiles/GameOfLife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameOfLife.dir/depend

