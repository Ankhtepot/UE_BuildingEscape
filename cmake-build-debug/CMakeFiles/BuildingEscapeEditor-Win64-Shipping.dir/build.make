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

# Utility rule file for BuildingEscapeEditor-Win64-Shipping.

# Include the progress variables for this target.
include CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/progress.make

CMakeFiles/BuildingEscapeEditor-Win64-Shipping:
	call "D:/Games/Epic Games/UE_4.25/Engine/Build/BatchFiles/Build.bat" BuildingEscapeEditor Win64 Shipping "-project=D:/Unreal/Unreal projects/course/BuildingEscape/BuildingEscape.uproject" -game -progress -buildscw

BuildingEscapeEditor-Win64-Shipping: CMakeFiles/BuildingEscapeEditor-Win64-Shipping
BuildingEscapeEditor-Win64-Shipping: CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/build.make

.PHONY : BuildingEscapeEditor-Win64-Shipping

# Rule to build all files generated by this target.
CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/build: BuildingEscapeEditor-Win64-Shipping

.PHONY : CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/build

CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BuildingEscapeEditor-Win64-Shipping.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/clean

CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Unreal\Unreal projects\course\BuildingEscape" "D:\Unreal\Unreal projects\course\BuildingEscape" "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug" "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug" "D:\Unreal\Unreal projects\course\BuildingEscape\cmake-build-debug\CMakeFiles\BuildingEscapeEditor-Win64-Shipping.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BuildingEscapeEditor-Win64-Shipping.dir/depend

