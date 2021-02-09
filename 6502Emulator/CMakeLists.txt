# CMakeList.txt : CMake project for 6502Emulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (6502Emulator "6502Emulator.cpp" "6502Emulator.h" "6502Memory.h" "6502Types.h" "6502Memory.cpp" "6502CPU.cpp" "6502CPU.h" "6502OpCodes.h" "6502OpCodes.cpp" "6502Registers.h" "6502Registers.cpp")

# TODO: Add tests and install targets if needed.
