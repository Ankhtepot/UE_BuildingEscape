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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Unreal\Unreal projects\course\BuildingEscape"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug"

# Utility rule file for BuildingEscape-Win64-DebugGame.

# Include the progress variables for this target.
include CMakeFiles/BuildingEscape-Win64-DebugGame.dir/progress.make

CMakeFiles/BuildingEscape-Win64-DebugGame:
	call "D:/Games/Epic Games/UE_4.25/Engine/Build/BatchFiles/Build.bat" BuildingEscape Win64 DebugGame "-project=D:/Unreal/Unreal projects/course/BuildingEscape/BuildingEscape.uproject" -game -progress -buildscw

BuildingEscape-Win64-DebugGame: CMakeFiles/BuildingEscape-Win64-DebugGame
BuildingEscape-Win64-DebugGame: CMakeFiles/BuildingEscape-Win64-DebugGame.dir/build.make

.PHONY : BuildingEscape-Win64-DebugGame

# Rule to build all files generated by this target.
CMakeFiles/BuildingEscape-Win64-DebugGame.dir/build: BuildingEscape-Win64-DebugGame

.PHONY : CMakeFiles/BuildingEscape-Win64-DebugGame.dir/build

CMakeFiles/BuildingEscape-Win64-DebugGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BuildingEscape-Win64-DebugGame.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BuildingEscape-Win64-DebugGame.dir/clean

CMakeFiles/BuildingEscape-Win64-DebugGame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Unreal\Unreal projects\course\BuildingEscape" "D:\Unreal\Unreal projects\course\BuildingEscape" "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug" "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug" "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug\CMakeFiles\BuildingEscape-Win64-DebugGame.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BuildingEscape-Win64-DebugGame.dir/depend

