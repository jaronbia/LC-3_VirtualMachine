#include "Emulator.hpp"

void Emulator::
run() {
    bool active = true;
    uint16_t instr;
    uint16_t op;
    // load args
    // setup

    reg[PC] = PC_START;
    
    while(active) {
        instr = mem_read(reg[PC]++);
        op = instr >> 12;

        if(op == ADD) add(instr);
        else cerr << "Error: Invalid command encountered" << '\n';
    }
    // shutdown
}

void Emulator::
add(int instr) {
    bool immFlag = (instr >> 5) & 0x1;      // are we in immediate mode? (originally uint16_t)
    uint16_t r0 = (instr >> 9) & 0x7;       // destination register
    uint16_t r1 = (instr >> 6) & 0x7;       // first operand

    if(immFlag) {
        uint16_t imm5 = signExtend(instr & 0x1F, 5);
        reg[r0] = reg[r1] + imm5;
    }
    else {
        uint16_t r2 = instr & 0x7;
        reg[r0] = reg[r1] + reg[r2];
    }

    updateFlag(r0);
}