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
CMAKE_SOURCE_DIR = /home/sparrow/Documents/WashU/521/marble_map_nevigate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sparrow/Documents/WashU/521/marble_map_nevigate/build

# Include any dependencies generated for this target.
include CMakeFiles/521.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/521.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/521.dir/flags.make

CMakeFiles/521.dir/main.cpp.o: CMakeFiles/521.dir/flags.make
CMakeFiles/521.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sparrow/Documents/WashU/521/marble_map_nevigate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/521.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/521.dir/main.cpp.o -c /home/sparrow/Documents/WashU/521/marble_map_nevigate/main.cpp

CMakeFiles/521.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/521.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sparrow/Documents/WashU/521/marble_map_nevigate/main.cpp > CMakeFiles/521.dir/main.cpp.i

CMakeFiles/521.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/521.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sparrow/Documents/WashU/521/marble_map_nevigate/main.cpp -o CMakeFiles/521.dir/main.cpp.s

# Object files for target 521
521_OBJECTS = \
"CMakeFiles/521.dir/main.cpp.o"

# External object files for target 521
521_EXTERNAL_OBJECTS =

521: CMakeFiles/521.dir/main.cpp.o
521: CMakeFiles/521.dir/build.make
521: /usr/lib/x86_64-linux-gnu/libmarblewidget-qt5.so.21.7.20
521: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
521: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
521: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.12.8
521: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
521: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
521: CMakeFiles/521.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sparrow/Documents/WashU/521/marble_map_nevigate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 521"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/521.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/521.dir/build: 521

.PHONY : CMakeFiles/521.dir/build

CMakeFiles/521.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/521.dir/cmake_clean.cmake
.PHONY : CMakeFiles/521.dir/clean

CMakeFiles/521.dir/depend:
	cd /home/sparrow/Documents/WashU/521/marble_map_nevigate/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sparrow/Documents/WashU/521/marble_map_nevigate /home/sparrow/Documents/WashU/521/marble_map_nevigate /home/sparrow/Documents/WashU/521/marble_map_nevigate/build /home/sparrow/Documents/WashU/521/marble_map_nevigate/build /home/sparrow/Documents/WashU/521/marble_map_nevigate/build/CMakeFiles/521.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/521.dir/depend
