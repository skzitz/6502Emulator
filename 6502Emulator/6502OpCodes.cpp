#include "6502OpCodes.h"

OpCodes::OpCodes(Registers* reg, Memory* mem) {
	registers = reg;
	memory = mem;
}

OpCodes::~OpCodes() {

}
