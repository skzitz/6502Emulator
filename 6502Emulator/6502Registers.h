#pragma once

#include "6502Types.h"

struct ProcessorStatus {
	BYTE cf : 1;	// CarryFlag
	BYTE zf : 1;	// ZeroFlag
	BYTE id : 1;	// InterruptDisable
	BYTE dm : 1;	// DecimalMode
	BYTE bc : 1;	// BreakCommand
	BYTE unused : 1;
	BYTE of : 1;	// OverflowFlag
	BYTE nf : 1;	// NegativeFlag
};

class Registers {
private:
	WORD pc;	// ProgramCounter
	BYTE sp;	// StackPointer
	BYTE a;		// A Register
	BYTE x;		// X Register
	BYTE y;		// Y Register
	union {
		ProcessorStatus flags;
		BYTE            PS;
	};

public:
	Registers();
	~Registers();

	void dump() const;

	WORD PC() const;
	void PC(WORD newPC);

	BYTE SP() const;
	void SP(BYTE newSP);

	BYTE A() const;
	void A(BYTE newA);

	BYTE X() const;
	void X(BYTE newX);

	BYTE Y() const;
	void Y(BYTE newY);

	BYTE FLAGS() const;
	void FLAGS(BYTE newFLAGS);

	void setZeroFlag(BYTE flag);
	BYTE ZF() const;

	void setCarryFlag(BYTE flag);
	BYTE CF() const;

	void setNegativeFlag(BYTE flag);
	BYTE NF() const;

	void setOverflowFlag(BYTE flag);
	BYTE OF() const;
};

