#include "6502Memory.h"

#include <stdio.h>
#include <memory.h>

Memory::Memory() {
	stackOffset = 0x0100;
	memset(memory, 0, MEM_SIZE);
}

Memory::Memory(BYTE* buffer, uint32_t size, uint32_t stackOff) {
	if (size > MEM_SIZE) {
		// should alert here, perhaps
		size = MEM_SIZE;
	}
	memcpy(memory, buffer, size);
	stackOffset = stackOff;
}

Memory::~Memory() {

}

BYTE Memory::operator[](uint32_t offset) const {
	return memory[offset];
}

BYTE& Memory::operator[](uint32_t offset) {
	return memory[offset];
}

void Memory::putOnStack(uint32_t offset, BYTE value) {
	// should perhaps verify offset <= 255
	// should perhaps verify stackOffset+offset <= MEM_SIZE
	memory[stackOffset + offset] = value;
}
BYTE Memory::getFromStack(uint32_t offset) const {
	// should perhaps verify offset <= 255
	// should perhaps verify stackOffset+offset <= MEM_SIZE
	return memory[stackOffset + offset];
}

BYTE Memory::stack(uint32_t offset) const {
	return memory[offset + stackOffset];
}

BYTE& Memory::stack(uint32_t offset) {
	return memory[offset + stackOffset];
}
