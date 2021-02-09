// 6502Memory.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stdio.h>
#include <memory.h>
#include <cstdint>

#include "6502Types.h"

class Memory {
private:
	static constexpr uint32_t MEM_SIZE = 1024 * 64;
	static constexpr uint8_t STACK_SIZE = 255;
	uint32_t stackOffset;
	BYTE     memory[MEM_SIZE];

public:
	Memory();
	Memory(BYTE* buffer, uint32_t size, uint32_t stackOff );
	~Memory();

	virtual BYTE operator[](uint32_t offset) const;
	virtual BYTE& operator[](uint32_t offset);

	BYTE* getMemory() const;

	BYTE stack(uint32_t offset) const;
	BYTE& stack(uint32_t offset);

	void putOnStack(uint32_t offset, BYTE value);
	BYTE getFromStack(uint32_t offset) const;

	void dump() const;
	void dumpStack() const;
};