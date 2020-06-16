#include "VirtualMachine.hpp"

/********************************
 *   Virtual Machine Functions  *
*********************************/

void VirtualMachine::
run() {
    bool active = true;
    uint16_t instr, op;
    Trap tr(&mem, &reg[R0]);
    // load args

    // setup
    signal(SIGINT, mem->interrupt());
    mem->disableInput();

    reg[PC] = PC_START;
    
    while(active) {
        instr = mem->read(reg[PC]++);
        op = instr >> 12;

        if(op == ADD)       add(instr);
        else if(op == LDI)  ldi(instr);
        else if(op == BR)   branch(instr);
        else if(op == JMP)  jump(instr);
        else if(op == JSR)  jsr(instr);
        else if(op == LD)   load(instr);
        else if(op == LDR)  loadr(instr);
        else if(op == LEA)  loadea(instr);
        else if(op == ST)   store(instr);
        else if(op == STI)  storei(instr);
        else if(op == STR)  storer(instr);
        else if(op == TRAP) tr.execute(instr, active);
        else abort();
    }
    // shutdown
    mem->restoreInput()
}

void VirtualMachine::
add(const int instr)  {
    uint16_t r0 = (instr >> 9) & 0x7;                             // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                             // first operand
    uint16_t val = isImmMode(instr) ? signExtend(instr & 0x1F, 5) // if immediate
                                    : reg[instr & 0x7];           // else register value

    reg[r0] = reg[r1] + val;
    updateFlag(r0);
}

void VirtualMachine::
ldi(const int instr)  {
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                   // first operand

    reg[r0] = mem->read(mem->read(reg[PC] + pcoffset(instr)));
    updateFlag(r0);
}

void VirtualMachine::
band(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;                              // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                              // first operand
    uint16_t val = isImmMode(instr) ? signExtend(instr & 0x1F, 5)  // if immediate
                                    : reg[instr & 0x7];            // else register value

    reg[r0] = reg[r1] & val;
    updateFlag(r0);
}

void VirtualMachine:: 
bnot(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;                    // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                    // first operand

    reg[r0] = ~reg[r1];
    updateFlag(r0);
}

void VirtualMachine::
branch(const int instr) {
    uint16_t condFlag = (instr >> 9) & 0x7;
    if(condFlag & reg[COND]) reg[PC] += pcoffset(instr);   
}

void VirtualMachine:: 
jsr(const int instr) {
    uint16_t r1 = (instr >> 6) & 0x7;                   // first operand
    uint16_t longFlag = (instr >> 11) & 1;

    reg[R7] = reg[PC];
    reg[PC] = longFlag ? reg[PC] + longpcoffset(instr)
                       : reg[r1];
}

void VirtualMachine::
load(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register

    reg[r0] = mem->read(reg[PC] + pcoffset(instr));
    updateFlag(r0);
}

void VirtualMachine:: 
loadr(const int instr) {                                // load register
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register
    uint16_t r1 = (instr >> 6) & 0x7;                   // first operand

    reg[r0] = mem->read(reg[r1] + offset(instr));
    updateFlag(r0);
}   

void VirtualMachine:: 
loadea(const int instr) {                               // load effective address
    uint16_t r0 = (instr >> 9) & 0x7;                   // destination register
    
    reg[r0] = reg[PC] + pcoffset(instr);
    updateFlag(r0);
}

void VirtualMachine:: 
store(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;
    mem->write(reg[PC] + pcoffset(instr), reg[r0]);
}

void VirtualMachine:: 
storei(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;
    mem->write(mem->read(reg[PC] + pcoffset(instr)), reg[r0]);
}

void VirtualMachine:: 
storer(const int instr) {
    uint16_t r0 = (instr >> 9) & 0x7;
    uint16_t r1 = (instr >> 6) & 0x7;  
    mem->write(reg[r1] + offset(instr), reg[r0]);
}

void VirtualMachine::
updateFlag(const uint16_t r) {
    if(reg[r] == 0) reg[COND] = FL_ZRO;
    else reg[COND] = (reg[r] >> 15) ? FL_NEG 
                                    : FL_POS;
}

/********************************
 *        Trap Functions        *
*********************************/

void Trap:: 
execute(const uint16_t instr, const bool& active) {
    uint16_t tr = instr & 0xFF;

    if(tr == GETC)       getc();
    else if(tr == OUT)   out();
    else if(tr == PUTS)  trputs();
    else if(tr == IN)    in();
    else if(tr == PUTSP) putsp();
    else if(tr == HALT)  halt(active);
    //else
}

 /* one char per word */
void Trap::
trputs() {
    for (uint16_t* c = mem->loc(reg); *c; ++c) 
        putc((char)*c, stdout);
    fflush(stdout);
}

void Trap::
in() {
    printf("Enter a character: ");
    char c = getchar();
    putc(c, stdout);
    *reg = (uint16_t) c;
}

/* 
   one char per byte (two bytes per word)
   here we need to swap back to
   big endian format 
*/
void Trap::
putsp() {
    char ch;

    for(uint16_t* c = mem->loc(reg); *c; ++c) {
        ch = (*c) & 0xFF;
        putc(ch, stdout);
        ch = (*c) >> 8;
        if(ch) putc(ch, stdout);
    }

    fflush(stdout);
}

void Trap:: 
halt(bool active) {
    puts("HALT");
    fflush(stdout);
    active = false;
}