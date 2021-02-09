#include "6502Registers.h"
#include "6502Types.h"
#include <stdio.h>

Registers::Registers() {
	pc = 0;
	sp = 0;
	a = 0;
	x = 0;
	y = 0;
}

Registers::~Registers() {

}

void Registers::dump() const {
	printf("pc = [0x%X]\n", pc);
	printf("sp = [0x%X]\n", sp);
	printf(" a = [0x%X]\n", a);
	printf(" x = [0x%X]\n", x);
	printf(" y = [0x%X]\n", y);
	printf("CZIDB ON\n");
	printf("%d", flags.cf ? 1 : 0);
	printf("%d", flags.zf ? 1 : 0);
	printf("%d", flags.id ? 1 : 0);
	printf("%d", flags.dm ? 1 : 0);
	printf("%d", flags.bc ? 1 : 0);
	printf(" ");
	printf("%d", flags.of ? 1 : 0);
	printf("%d", flags.nf ? 1 : 0);
	printf("\n");
}

WORD Registers::PC() const {
	return pc;
}

void Registers::PC(WORD newPC) {
	pc = newPC;
}

BYTE Registers::SP() const {
	return sp;
}

void Registers::SP(BYTE newSP) {
	sp = newSP;
}

BYTE Registers::A() const {
	return a;
}

void Registers::A(BYTE newA) {
	a = newA;
}

BYTE Registers::X() const {
	return x;
}

void Registers::X(BYTE newX) {
	x = newX;
}

BYTE Registers::Y() const {
	return y;
}

void Registers::Y(BYTE newY) {
	y = newY;
}

BYTE Registers::FLAGS() const {
	return PS;
}

void Registers::FLAGS(BYTE newFLAGS) {
	PS = newFLAGS;
}

void Registers::setZeroFlag(BYTE flag) {
	flags.zf = (flag != 0x00);
}

void Registers::setCarryFlag(BYTE flag) {
	flags.cf = (flag != 0x00);
}

void Registers::setNegativeFlag(BYTE flag) {
	flags.nf = (flag != 0x00);
}

void Registers::setOverflowFlag(BYTE flag) {
	flags.of = (flag != 0x00);
}

BYTE Registers::ZF() const {
	return flags.zf;
}

BYTE Registers::CF() const {
	return flags.cf;
}

BYTE Registers::NF() const {
	return flags.nf;
}

BYTE Registers::OF() const {
	return flags.of;
}
