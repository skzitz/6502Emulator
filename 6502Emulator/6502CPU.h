// 6502CPU.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <cstdint>

#include "6502Types.h"
#include "6502Memory.h"
#include "6502Registers.h"
#include "6502OpCodes.h"

class CPU {
private:
	Registers* registers;
	Memory* memory;
	OpCodes* opcodes;

public:
	CPU(Memory* mem = nullptr, Registers* reg = nullptr, OpCodes* oc = nullptr );
	~CPU();

	Memory* getMemory() { return memory; }
	Registers* getRegisters() { return registers; }
	OpCodes* getOpCodes() { return opcodes; }
};
