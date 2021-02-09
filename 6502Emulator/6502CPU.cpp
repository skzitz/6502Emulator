// 6502CPU.cpp : Defines the entry point for the application.
//

#include <stdio.h>
#include <iostream>

#include "6502CPU.h"

#include "6502Types.h"
#include "6502Memory.h"
#include "6502Registers.h"
#include "6502OpCodes.h"

CPU::CPU( Memory* mem, Registers* reg, OpCodes* oc) {
	if (nullptr == mem) {
		mem = new Memory();
	}
	if (nullptr == reg) {
		reg = new Registers();
	}
	memory = mem;
	registers = reg;
	opcodes = oc;

	if (nullptr == oc) {
		oc = new OpCodes(registers, memory);
	}
}

CPU::~CPU() {
	if (nullptr != memory) {
		delete memory;
	}
	if (nullptr != registers) {
		delete registers;
	}
}


