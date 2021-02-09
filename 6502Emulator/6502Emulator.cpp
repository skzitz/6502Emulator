// 6502Emulator.cpp : Defines the entry point for the application.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "6502Emulator.h"
#include "6502CPU.h"

using namespace std;

int main(){
	Memory* memory = new Memory();
	CPU* cpu = new CPU(memory);
	memory->stack(0) = 0xDE;
	memory->stack(1) = 0xAD;
	memory->stack(2) = 0xBE;
	memory->stack(3) = 0xEF;

	BYTE atStack = memory->stack(1);
	cout << showbase
		<< internal
		<< setfill('0');
	cout << "atStack = [" << hex << (int)atStack << "]" << endl;
	return 0;
}
