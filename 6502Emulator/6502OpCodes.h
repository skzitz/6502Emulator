#pragma once

#include "6502Types.h"
#include "6502Registers.h"
#include "6502Memory.h"

// see http://www.obelisk.me.uk/index.html
// also, thanks to https://github.com/davepoo (and https://github.com/davepoo/6502Emulator)
static constexpr BYTE
//load/store operations
//LDA	Load Accumulator					n,z
INS_LDA_IM = 0xA9,
INS_LDA_ZP = 0xA5,
INS_LDA_ZPX = 0xB5,
INS_LDA_ABS = 0xAD,
INS_LDA_ABSX = 0xBD,
INS_LDA_ABSY = 0xB9,
INS_LDA_INDX = 0xA1,
INS_LDA_INDY = 0xB1,
//LDX	Load X Register						n,z
INS_LDX_IM = 0xA2,
INS_LDX_ZP = 0xA6,
INS_LDX_ZPY = 0xB6,
INS_LDX_ABS = 0xAE,
INS_LDX_ABSY = 0xBE,
//LDY	Load Y Register						n,z
INS_LDY_IM = 0xA0,
INS_LDY_ZP = 0xA4,
INS_LDY_ZPX = 0xB4,
INS_LDY_ABS = 0xAC,
INS_LDY_ABSX = 0xBC,
//STA	Store Accumulator
INS_STA_ZP = 0x85,
INS_STA_ZPX = 0x95,
INS_STA_ABS = 0x8D,
INS_STA_ABSX = 0x9D,
INS_STA_ABSY = 0x99,
INS_STA_INDX = 0x81,
INS_STA_INDY = 0x91,
//STX	Store X Register
INS_STX_ZP = 0x86,
INS_STX_ZPY = 0x96,
INS_STX_ABS = 0x8E,
//STY	Store Y Register
INS_STY_ZP = 0x84,
INS_STY_ZPX = 0x94,
INS_STY_ABS = 0x8C,

//register transfers
//TAX	Transfer Accumulator to X			n.z
INS_TAX = 0xAA,
//TAY	Transfer Accumulator to Y			n.z
INS_TAY = 0xA8,
//TXA	Transfer X to Accumulator			n.z
INS_TXA = 0x8A,
//TYA	Transfer Y to Accumulator			n.z
INS_TYA = 0x98,

//stack operations
//TSX	Transfer SP to X					n,z
INS_TSX = 0xBA,
//TXS	Transfer X to SP
INS_TXS = 0x9A,
//PHA	Push Accumulator on stack
INS_PHA = 0x48,
//PLA	Pull Accumulator from stack			n,z
INS_PLA = 0x68,
//PHP	Push Processor Status on stack
INS_PHP = 0x08,
//PLP	Pull Processor Status from stack	ALL
INS_PLP = 0x28,

//logical
//AND	Logical AND							n,z
INS_AND_IM = 0x29,
INS_AND_ZP = 0x25,
INS_AND_ZPX = 0x35,
INS_AND_ABS = 0x2D,
INS_AND_ABSX = 0x3D,
INS_AND_ABSY = 0x39,
INS_AND_INDX = 0x21,
INS_AND_INDY = 0x31,
//EOR	XOR									n,z
INS_EOR_IM = 0x49,
INS_EOR_ZP = 0x45,
INS_EOR_ZPX = 0x55,
INS_EOR_ABS = 0x4D,
INS_EOR_ABSX = 0x5D,
INS_EOR_ABSY = 0x59,
INS_EOR_INDX = 0x41,
INS_EOR_INDY = 0x51,
//ORA	OR									n,z
INS_ORA_IM = 0x09,
INS_ORA_ZP = 0x05,
INS_ORA_ZPX = 0x15,
INS_ORA_ABS = 0x0D,
INS_ORA_ABSX = 0x1D,
INS_ORA_ABSY = 0x19,
INS_ORA_INDX = 0x01,
INS_ORA_INDY = 0x11,
//BIT	Bit Test							n,v,z
INS_BIT_ZP = 0x24,
INS_BIT_ABS = 0x2C,

//arithmetic
//ADC	Add with carry						n,v,z,c
INS_ADC = 0x69,
INS_ADC_ZP = 0x65,
INS_ADC_ZPX = 0x75,
INS_ADC_ABS = 0x6D,
INS_ADC_ABSX = 0x7D,
INS_ADC_ABSY = 0x79,
INS_ADC_INDX = 0x61,
INS_ADC_INDY = 0x71,
//SBC	Subtract with carry					n,v,z,c
INS_SBC = 0xE9,
INS_SBC_ABS = 0xED,
INS_SBC_ZP = 0xE5,
INS_SBC_ZPX = 0xF5,
INS_SBC_ABSX = 0xFD,
INS_SBC_ABSY = 0xF9,
INS_SBC_INDX = 0xE1,
INS_SBC_INDY = 0xF1,
//CMP	Compare accumulator					n,z,c
INS_CMP = 0xC9,
INS_CMP_ZP = 0xC5,
INS_CMP_ZPX = 0xD5,
INS_CMP_ABS = 0xCD,
INS_CMP_ABSX = 0xDD,
INS_CMP_ABSY = 0xD9,
INS_CMP_INDX = 0xC1,
INS_CMP_INDY = 0xD1,
//CPX	Compare X Register					n,z,c
INS_CPX = 0xE0,
INS_CPX_ZP = 0xE4,
INS_CPX_ABS = 0xEC,
//CPY	Compare Y Register					n,z,c
INS_CPY = 0xC0,
INS_CPY_ZP = 0xC4,
INS_CPY_ABS = 0xCC,

//increment & decrements
//INC	Increment a memory location			n,z
INS_INC_ZP = 0xE6,
INS_INC_ZPX = 0xF6,
INS_INC_ABS = 0xEE,
INS_INC_ABSX = 0xFE,
//INX	Increment X							n,z
INS_INX = 0xE8,
//INY	Increment Y							n,z
INS_INY = 0xC8,
//DEC	Decrement a memory location			n,z
INS_DEC_ZP = 0xC6,
INS_DEC_ZPX = 0xD6,
INS_DEC_ABS = 0xCE,
INS_DEC_ABSX = 0xDE,
//DEX	Decrement X							n,z
INS_DEX = 0xCA,
//DEY	Decrement Y							n,z
INS_DEY = 0x88,

//shifts
//ASL	Arithmetic shift left				n,z,c
INS_ASL = 0x0A,
INS_ASL_ZP = 0x06,
INS_ASL_ZPX = 0x16,
INS_ASL_ABS = 0x0E,
INS_ASL_ABSX = 0x1E,
//LSR	Logical shift right					n,z,c
INS_LSR = 0x4A,
INS_LSR_ZP = 0x46,
INS_LSR_ZPX = 0x56,
INS_LSR_ABS = 0x4E,
INS_LSR_ABSX = 0x5E,
//ROL	Rotate left							n,z,c
INS_ROL = 0x2A,
INS_ROL_ZP = 0x26,
INS_ROL_ZPX = 0x36,
INS_ROL_ABS = 0x2E,
INS_ROL_ABSX = 0x3E,
//ROR	Rotate right						n,z,c
INS_ROR = 0x6A,
INS_ROR_ZP = 0x66,
INS_ROR_ZPX = 0x76,
INS_ROR_ABS = 0x6E,
INS_ROR_ABSX = 0x7E,

//jumps & calls
//JMP	Jump to another location
INS_JMP_ABS = 0x4C,
INS_JMP_IND = 0x6C,
//JSR	Jump to a subroutine
INS_JSR = 0x20,
//RTS	Return from subroutine
INS_RTS = 0x60,

//branches
//BCC	Branch if carry flag clear
INS_BCC = 0x90,
//BCS	Branch if carry flag set
INS_BCS = 0xB0,
//BEQ	Branch if zero flag set
INS_BEQ = 0xF0,
//BMI	Branch if negative flag set
INS_BMI = 0x30,
//BNE	Branch if zero flag clear
INS_BNE = 0xD0,
//BPL	Branch if negative flag clear
INS_BPL = 0x10,
//BVC	Branch if overflow flag clear
INS_BVC = 0x50,
//BVS	Branch if overflow flag set
INS_BVS = 0x70,

//status flags
//CLC	Clear carry flag					c
INS_CLC = 0x18,
//CLD	Clear decimal flag					d
INS_CLD = 0xD8,
//CLI	Clear interrupt disable flag		i
INS_CLI = 0x58,
//CLV	Clear overflow flag					v
INS_CLV = 0xB8,
//SEC	Set carry flag						c
INS_SEC = 0x38,
//SED	Set decimal flag					d
INS_SED = 0xF8,
//SEI	Set interrupt disable flag			i
INS_SEI = 0x78,

//system functions
//BRK	Force an interrupt					b
INS_BRK = 0x00,
//NOP	No operation
INS_NOP = 0xEA,
//RTI	Return from interrupt				all
INS_RTI = 0x40;



class OpCodes {
private:
	Registers* registers;
	Memory*    memory;

public:
	OpCodes(Registers* reg, Memory* mem);
	~OpCodes();


};
