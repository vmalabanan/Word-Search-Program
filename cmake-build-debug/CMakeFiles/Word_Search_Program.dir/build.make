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
include CMakeFiles/Word_Search_Program.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Word_Search_Program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Word_Search_Program.dir/flags.make

CMakeFiles/Word_Search_Program.dir/main.cpp.obj: CMakeFiles/Word_Search_Program.dir/flags.make
CMakeFiles/Word_Search_Program.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Word_Search_Program.dir/main.cpp.obj"
	C:\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Word_Search_Program.dir\main.cpp.obj -c "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\main.cpp"

CMakeFiles/Word_Search_Program.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Word_Search_Program.dir/main.cpp.i"
	C:\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\main.cpp" > CMakeFiles\Word_Search_Program.dir\main.cpp.i

CMakeFiles/Word_Search_Program.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Word_Search_Program.dir/main.cpp.s"
	C:\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\main.cpp" -o CMakeFiles\Word_Search_Program.dir\main.cpp.s

# Object files for target Word_Search_Program
Word_Search_Program_OBJECTS = \
"CMakeFiles/Word_Search_Program.dir/main.cpp.obj"

# External object files for target Word_Search_Program
Word_Search_Program_EXTERNAL_OBJECTS =

Word_Search_Program.exe: CMakeFiles/Word_Search_Program.dir/main.cpp.obj
Word_Search_Program.exe: CMakeFiles/Word_Search_Program.dir/build.make
Word_Search_Program.exe: CMakeFiles/Word_Search_Program.dir/linklibs.rsp
Word_Search_Program.exe: CMakeFiles/Word_Search_Program.dir/objects1.rsp
Word_Search_Program.exe: CMakeFiles/Word_Search_Program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Word_Search_Program.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Word_Search_Program.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Word_Search_Program.dir/build: Word_Search_Program.exe
.PHONY : CMakeFiles/Word_Search_Program.dir/build

CMakeFiles/Word_Search_Program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Word_Search_Program.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Word_Search_Program.dir/clean

CMakeFiles/Word_Search_Program.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug" "C:\Users\vanes\Dropbox\#zqC++ Projects\zCS 002\Word Search Program\cmake-build-debug\CMakeFiles\Word_Search_Program.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Word_Search_Program.dir/depend

