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
CMAKE_COMMAND = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/daynumofyear.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/daynumofyear.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/daynumofyear.dir/flags.make

CMakeFiles/daynumofyear.dir/daynumofyear.cpp.o: CMakeFiles/daynumofyear.dir/flags.make
CMakeFiles/daynumofyear.dir/daynumofyear.cpp.o: ../daynumofyear.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/daynumofyear.dir/daynumofyear.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/daynumofyear.dir/daynumofyear.cpp.o -c "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/daynumofyear.cpp"

CMakeFiles/daynumofyear.dir/daynumofyear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daynumofyear.dir/daynumofyear.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/daynumofyear.cpp" > CMakeFiles/daynumofyear.dir/daynumofyear.cpp.i

CMakeFiles/daynumofyear.dir/daynumofyear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daynumofyear.dir/daynumofyear.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/daynumofyear.cpp" -o CMakeFiles/daynumofyear.dir/daynumofyear.cpp.s

# Object files for target daynumofyear
daynumofyear_OBJECTS = \
"CMakeFiles/daynumofyear.dir/daynumofyear.cpp.o"

# External object files for target daynumofyear
daynumofyear_EXTERNAL_OBJECTS =

daynumofyear: CMakeFiles/daynumofyear.dir/daynumofyear.cpp.o
daynumofyear: CMakeFiles/daynumofyear.dir/build.make
daynumofyear: CMakeFiles/daynumofyear.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable daynumofyear"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/daynumofyear.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/daynumofyear.dir/build: daynumofyear

.PHONY : CMakeFiles/daynumofyear.dir/build

CMakeFiles/daynumofyear.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/daynumofyear.dir/cmake_clean.cmake
.PHONY : CMakeFiles/daynumofyear.dir/clean

CMakeFiles/daynumofyear.dir/depend:
	cd "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/daynumofyear/cmake-build-debug/CMakeFiles/daynumofyear.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/daynumofyear.dir/depend
