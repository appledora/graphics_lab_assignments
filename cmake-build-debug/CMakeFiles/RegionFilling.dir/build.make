# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Appledora\CLionProjects\RegionFilling

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Appledora\CLionProjects\RegionFilling\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RegionFilling.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RegionFilling.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RegionFilling.dir/flags.make

CMakeFiles/RegionFilling.dir/main.cpp.obj: CMakeFiles/RegionFilling.dir/flags.make
CMakeFiles/RegionFilling.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Appledora\CLionProjects\RegionFilling\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RegionFilling.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RegionFilling.dir\main.cpp.obj -c C:\Users\Appledora\CLionProjects\RegionFilling\main.cpp

CMakeFiles/RegionFilling.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RegionFilling.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Appledora\CLionProjects\RegionFilling\main.cpp > CMakeFiles\RegionFilling.dir\main.cpp.i

CMakeFiles/RegionFilling.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RegionFilling.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Appledora\CLionProjects\RegionFilling\main.cpp -o CMakeFiles\RegionFilling.dir\main.cpp.s

# Object files for target RegionFilling
RegionFilling_OBJECTS = \
"CMakeFiles/RegionFilling.dir/main.cpp.obj"

# External object files for target RegionFilling
RegionFilling_EXTERNAL_OBJECTS =

RegionFilling.exe: CMakeFiles/RegionFilling.dir/main.cpp.obj
RegionFilling.exe: CMakeFiles/RegionFilling.dir/build.make
RegionFilling.exe: CMakeFiles/RegionFilling.dir/linklibs.rsp
RegionFilling.exe: CMakeFiles/RegionFilling.dir/objects1.rsp
RegionFilling.exe: CMakeFiles/RegionFilling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Appledora\CLionProjects\RegionFilling\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RegionFilling.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RegionFilling.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RegionFilling.dir/build: RegionFilling.exe

.PHONY : CMakeFiles/RegionFilling.dir/build

CMakeFiles/RegionFilling.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RegionFilling.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RegionFilling.dir/clean

CMakeFiles/RegionFilling.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Appledora\CLionProjects\RegionFilling C:\Users\Appledora\CLionProjects\RegionFilling C:\Users\Appledora\CLionProjects\RegionFilling\cmake-build-debug C:\Users\Appledora\CLionProjects\RegionFilling\cmake-build-debug C:\Users\Appledora\CLionProjects\RegionFilling\cmake-build-debug\CMakeFiles\RegionFilling.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RegionFilling.dir/depend
