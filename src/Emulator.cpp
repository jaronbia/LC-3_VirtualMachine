#include "Emulator.hpp"

void Emulator::
run() {
    bool active = true;
    uint16_t instr, op;
    // load args
    // setup

    reg[PC] = PC_START;
    
    while(active) {
        instr = mem_read(reg[PC]++);
        op = instr >> 12;

        if(op == ADD)      add(instr);
        else if(op == LDI) ldi(instr);
        else if(op == BR)  branch(instr);
        else if(op == JMP) jump(instr);
        else if(op == JSR) jsr(instr);
        else if(op == LD)  load(instr);
        else if(op == LDR) loadr(instr);
        else if(op == LEA) loadea(instr);
        else abort(); //cerr << "Error: Invalid command encountered" << '\n';
    }
    // shutdown
}

void Emulator::
add(const int instr)  {
    uint16_t r0 = (instr >> 9) & 0x7;                    // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                    // first operand
    uint16_t val = isImmMode(instr) ? signExtend(instr & 0x1F, 5) // if immediate
                                    : reg[instr & 0x7];           // else register value

    reg[r0] = reg[r1] + val;
    updateFlag(r0);
}

void Emulator::
ldi(const int instr)  {
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                   // first operand

    reg[r0] = mem_read(mem_read(reg[PC] + pcoffset(instr)));
    updateFlag(r0);
}

void Emulator::
band(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;                    // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                    // first operand
    uint16_t val = isImmMode(instr) ? signExtend(instr & 0x1F, 5) // if immediate
                                    : reg[instr & 0x7];           // else register value

    reg[r0] = reg[r1] & val;
    updateFlag(r0);
}

void Emulator:: 
bnot(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;                    // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                    // first operand

    reg[r0] = ~reg[r1];
    updateFlag(r0);
}

void Emulator::
branch(const int instr) {
    uint16_t condFlag = (instr >> 9) & 0x7;
    if(condFlag & reg[COND]) reg[PC] += pcoffset(instr);   
}

void Emulator:: 
jsr(const int instr) {
    uint16_t r1 = (instr >> 6) & 0x7;                   // first operand
    uint16_t longFlag = (instr >> 11) & 1;

    reg[R7] = reg[PC];
    reg[PC] = longFlag ? reg[PC] + longpcoffset(instr)
                       : reg[r1];
}

void Emulator::
load(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register

    reg[r0] = mem_read(reg[PC] + pcoffset(instr));
    updateFlag(r0);
}

void Emulator:: 
    loadr(const int instr) {                            // load register
        uint16_t r0 = (instr >> 9) & 0x7;               // destination register
        uint16_t r1 = (instr >> 6) & 0x7;               // first operand

        reg[r0] = mem_read(reg[r1] + offset(instr));
        updateFlag(r0);
}   

void Emulator:: 
loadea(const int instr) {                               // load effective address
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register
    
    reg[r0] = reg[PC] + pcoffset(instr);
    updateFlag(r0);
}

void Emulator::
updateFlag(uint16_t r) {
    if(reg[r] == 0) reg[COND] = FL_ZRO;
    else reg[COND] = (reg[r] >> 15) ? FL_NEG 
                                    : FL_POS;
}