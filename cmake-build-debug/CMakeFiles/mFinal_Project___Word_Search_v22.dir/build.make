# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mFinal_Project___Word_Search_v22.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/mFinal_Project___Word_Search_v22.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mFinal_Project___Word_Search_v22.dir/flags.make

CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.obj: CMakeFiles/mFinal_Project___Word_Search_v22.dir/flags.make
CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.obj"
	C:\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mFinal_Project___Word_Search_v22.dir\main.cpp.obj -c "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\main.cpp"

CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.i"
	C:\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\main.cpp" > CMakeFiles\mFinal_Project___Word_Search_v22.dir\main.cpp.i

CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.s"
	C:\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\main.cpp" -o CMakeFiles\mFinal_Project___Word_Search_v22.dir\main.cpp.s

# Object files for target mFinal_Project___Word_Search_v22
mFinal_Project___Word_Search_v22_OBJECTS = \
"CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.obj"

# External object files for target mFinal_Project___Word_Search_v22
mFinal_Project___Word_Search_v22_EXTERNAL_OBJECTS =

mFinal_Project___Word_Search_v22.exe: CMakeFiles/mFinal_Project___Word_Search_v22.dir/main.cpp.obj
mFinal_Project___Word_Search_v22.exe: CMakeFiles/mFinal_Project___Word_Search_v22.dir/build.make
mFinal_Project___Word_Search_v22.exe: CMakeFiles/mFinal_Project___Word_Search_v22.dir/linklibs.rsp
mFinal_Project___Word_Search_v22.exe: CMakeFiles/mFinal_Project___Word_Search_v22.dir/objects1.rsp
mFinal_Project___Word_Search_v22.exe: CMakeFiles/mFinal_Project___Word_Search_v22.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mFinal_Project___Word_Search_v22.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mFinal_Project___Word_Search_v22.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mFinal_Project___Word_Search_v22.dir/build: mFinal_Project___Word_Search_v22.exe
.PHONY : CMakeFiles/mFinal_Project___Word_Search_v22.dir/build

CMakeFiles/mFinal_Project___Word_Search_v22.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mFinal_Project___Word_Search_v22.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mFinal_Project___Word_Search_v22.dir/clean

CMakeFiles/mFinal_Project___Word_Search_v22.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug\CMakeFiles\mFinal_Project___Word_Search_v22.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mFinal_Project___Word_Search_v22.dir/depend

