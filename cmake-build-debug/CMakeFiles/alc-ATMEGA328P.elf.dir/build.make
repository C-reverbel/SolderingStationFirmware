# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/alc-ATMEGA328P.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alc-ATMEGA328P.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alc-ATMEGA328P.elf.dir/flags.make

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj: CMakeFiles/alc-ATMEGA328P.elf.dir/flags.make
CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj: ../Source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\alc-ATMEGA328P.elf.dir\Source\main.cpp.obj -c C:\Users\carlos\Desktop\Git\SolderingStationFirmware\Source\main.cpp

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.i"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carlos\Desktop\Git\SolderingStationFirmware\Source\main.cpp > CMakeFiles\alc-ATMEGA328P.elf.dir\Source\main.cpp.i

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.s"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carlos\Desktop\Git\SolderingStationFirmware\Source\main.cpp -o CMakeFiles\alc-ATMEGA328P.elf.dir\Source\main.cpp.s

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.requires:

.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.requires

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.provides: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\alc-ATMEGA328P.elf.dir\build.make CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.provides.build
.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.provides

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.provides.build: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj


CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj: CMakeFiles/alc-ATMEGA328P.elf.dir/flags.make
CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj: ../Source/GPIO/GPIO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\alc-ATMEGA328P.elf.dir\Source\GPIO\GPIO.cpp.obj -c C:\Users\carlos\Desktop\Git\SolderingStationFirmware\Source\GPIO\GPIO.cpp

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.i"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\carlos\Desktop\Git\SolderingStationFirmware\Source\GPIO\GPIO.cpp > CMakeFiles\alc-ATMEGA328P.elf.dir\Source\GPIO\GPIO.cpp.i

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.s"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\carlos\Desktop\Git\SolderingStationFirmware\Source\GPIO\GPIO.cpp -o CMakeFiles\alc-ATMEGA328P.elf.dir\Source\GPIO\GPIO.cpp.s

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.requires:

.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.requires

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.provides: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.requires
	$(MAKE) -f CMakeFiles\alc-ATMEGA328P.elf.dir\build.make CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.provides.build
.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.provides

CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.provides.build: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj


# Object files for target alc-ATMEGA328P.elf
alc__ATMEGA328P_elf_OBJECTS = \
"CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj" \
"CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj"

# External object files for target alc-ATMEGA328P.elf
alc__ATMEGA328P_elf_EXTERNAL_OBJECTS =

alc-ATMEGA328P.elf: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj
alc-ATMEGA328P.elf: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj
alc-ATMEGA328P.elf: CMakeFiles/alc-ATMEGA328P.elf.dir/build.make
alc-ATMEGA328P.elf: CMakeFiles/alc-ATMEGA328P.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable alc-ATMEGA328P.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\alc-ATMEGA328P.elf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alc-ATMEGA328P.elf.dir/build: alc-ATMEGA328P.elf

.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/build

CMakeFiles/alc-ATMEGA328P.elf.dir/requires: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/main.cpp.obj.requires
CMakeFiles/alc-ATMEGA328P.elf.dir/requires: CMakeFiles/alc-ATMEGA328P.elf.dir/Source/GPIO/GPIO.cpp.obj.requires

.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/requires

CMakeFiles/alc-ATMEGA328P.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\alc-ATMEGA328P.elf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/clean

CMakeFiles/alc-ATMEGA328P.elf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles\alc-ATMEGA328P.elf.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alc-ATMEGA328P.elf.dir/depend

