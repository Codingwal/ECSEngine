# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\flori\Documents\Coding\C++\ECSEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\flori\Documents\Coding\C++\ECSEngine\build

# Include any dependencies generated for this target.
include engine/CMakeFiles/engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/CMakeFiles/engine.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include engine/CMakeFiles/engine.dir/flags.make

engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj: engine/CMakeFiles/engine.dir/flags.make
engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj: C:/Users/flori/Documents/Coding/C++/ECSEngine/engine/Entities/EntityManager.cpp
engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj: engine/CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\flori\Documents\Coding\C++\ECSEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj -MF CMakeFiles\engine.dir\Entities\EntityManager.cpp.obj.d -o CMakeFiles\engine.dir\Entities\EntityManager.cpp.obj -c C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Entities\EntityManager.cpp

engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/engine.dir/Entities/EntityManager.cpp.i"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Entities\EntityManager.cpp > CMakeFiles\engine.dir\Entities\EntityManager.cpp.i

engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/engine.dir/Entities/EntityManager.cpp.s"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Entities\EntityManager.cpp -o CMakeFiles\engine.dir\Entities\EntityManager.cpp.s

engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj: engine/CMakeFiles/engine.dir/flags.make
engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj: C:/Users/flori/Documents/Coding/C++/ECSEngine/engine/Components/ComponentManager.cpp
engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj: engine/CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\flori\Documents\Coding\C++\ECSEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj -MF CMakeFiles\engine.dir\Components\ComponentManager.cpp.obj.d -o CMakeFiles\engine.dir\Components\ComponentManager.cpp.obj -c C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Components\ComponentManager.cpp

engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/engine.dir/Components/ComponentManager.cpp.i"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Components\ComponentManager.cpp > CMakeFiles\engine.dir\Components\ComponentManager.cpp.i

engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/engine.dir/Components/ComponentManager.cpp.s"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Components\ComponentManager.cpp -o CMakeFiles\engine.dir\Components\ComponentManager.cpp.s

engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.obj: engine/CMakeFiles/engine.dir/flags.make
engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.obj: C:/Users/flori/Documents/Coding/C++/ECSEngine/engine/Entities/Archetype.cpp
engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.obj: engine/CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\flori\Documents\Coding\C++\ECSEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.obj"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.obj -MF CMakeFiles\engine.dir\Entities\Archetype.cpp.obj.d -o CMakeFiles\engine.dir\Entities\Archetype.cpp.obj -c C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Entities\Archetype.cpp

engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/engine.dir/Entities/Archetype.cpp.i"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Entities\Archetype.cpp > CMakeFiles\engine.dir\Entities\Archetype.cpp.i

engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/engine.dir/Entities/Archetype.cpp.s"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\flori\Documents\Coding\C++\ECSEngine\engine\Entities\Archetype.cpp -o CMakeFiles\engine.dir\Entities\Archetype.cpp.s

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj" \
"CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj" \
"CMakeFiles/engine.dir/Entities/Archetype.cpp.obj"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine/libengine.a: engine/CMakeFiles/engine.dir/Entities/EntityManager.cpp.obj
engine/libengine.a: engine/CMakeFiles/engine.dir/Components/ComponentManager.cpp.obj
engine/libengine.a: engine/CMakeFiles/engine.dir/Entities/Archetype.cpp.obj
engine/libengine.a: engine/CMakeFiles/engine.dir/build.make
engine/libengine.a: engine/CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\flori\Documents\Coding\C++\ECSEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libengine.a"
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && $(CMAKE_COMMAND) -P CMakeFiles\engine.dir\cmake_clean_target.cmake
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\engine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/CMakeFiles/engine.dir/build: engine/libengine.a
.PHONY : engine/CMakeFiles/engine.dir/build

engine/CMakeFiles/engine.dir/clean:
	cd /d C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine && $(CMAKE_COMMAND) -P CMakeFiles\engine.dir\cmake_clean.cmake
.PHONY : engine/CMakeFiles/engine.dir/clean

engine/CMakeFiles/engine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\flori\Documents\Coding\C++\ECSEngine C:\Users\flori\Documents\Coding\C++\ECSEngine\engine C:\Users\flori\Documents\Coding\C++\ECSEngine\build C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine C:\Users\flori\Documents\Coding\C++\ECSEngine\build\engine\CMakeFiles\engine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : engine/CMakeFiles/engine.dir/depend

