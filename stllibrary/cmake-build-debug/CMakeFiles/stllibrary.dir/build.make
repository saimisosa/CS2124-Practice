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
CMAKE_COMMAND = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/stllibrary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stllibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stllibrary.dir/flags.make

CMakeFiles/stllibrary.dir/main.cpp.o: CMakeFiles/stllibrary.dir/flags.make
CMakeFiles/stllibrary.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stllibrary.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stllibrary.dir/main.cpp.o -c "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/main.cpp"

CMakeFiles/stllibrary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stllibrary.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/main.cpp" > CMakeFiles/stllibrary.dir/main.cpp.i

CMakeFiles/stllibrary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stllibrary.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/main.cpp" -o CMakeFiles/stllibrary.dir/main.cpp.s

# Object files for target stllibrary
stllibrary_OBJECTS = \
"CMakeFiles/stllibrary.dir/main.cpp.o"

# External object files for target stllibrary
stllibrary_EXTERNAL_OBJECTS =

stllibrary: CMakeFiles/stllibrary.dir/main.cpp.o
stllibrary: CMakeFiles/stllibrary.dir/build.make
stllibrary: CMakeFiles/stllibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stllibrary"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stllibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stllibrary.dir/build: stllibrary

.PHONY : CMakeFiles/stllibrary.dir/build

CMakeFiles/stllibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stllibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stllibrary.dir/clean

CMakeFiles/stllibrary.dir/depend:
	cd "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/stllibrary/cmake-build-debug/CMakeFiles/stllibrary.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/stllibrary.dir/depend

