# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\JetBrains\Labs\Lab 4\code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\JetBrains\Labs\Lab 4\code\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/code.dir/flags.make

CMakeFiles/code.dir/main.cpp.obj: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\JetBrains\Labs\Lab 4\code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/code.dir/main.cpp.obj"
	C:\MINGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\code.dir\main.cpp.obj -c "C:\JetBrains\Labs\Lab 4\code\main.cpp"

CMakeFiles/code.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/main.cpp.i"
	C:\MINGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\JetBrains\Labs\Lab 4\code\main.cpp" > CMakeFiles\code.dir\main.cpp.i

CMakeFiles/code.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/main.cpp.s"
	C:\MINGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\JetBrains\Labs\Lab 4\code\main.cpp" -o CMakeFiles\code.dir\main.cpp.s

# Object files for target code
code_OBJECTS = \
"CMakeFiles/code.dir/main.cpp.obj"

# External object files for target code
code_EXTERNAL_OBJECTS =

code.exe: CMakeFiles/code.dir/main.cpp.obj
code.exe: CMakeFiles/code.dir/build.make
code.exe: CMakeFiles/code.dir/linklibs.rsp
code.exe: CMakeFiles/code.dir/objects1.rsp
code.exe: CMakeFiles/code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\JetBrains\Labs\Lab 4\code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable code.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\code.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/code.dir/build: code.exe

.PHONY : CMakeFiles/code.dir/build

CMakeFiles/code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\code.dir\cmake_clean.cmake
.PHONY : CMakeFiles/code.dir/clean

CMakeFiles/code.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\JetBrains\Labs\Lab 4\code" "C:\JetBrains\Labs\Lab 4\code" "C:\JetBrains\Labs\Lab 4\code\cmake-build-debug" "C:\JetBrains\Labs\Lab 4\code\cmake-build-debug" "C:\JetBrains\Labs\Lab 4\code\cmake-build-debug\CMakeFiles\code.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/code.dir/depend

