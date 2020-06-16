#pragma once
#include <cstdio>
#include <cstdint>
#include "UnixBuffer.hpp"
#define LC3_REGISTER_COUNT 11
#define PC_START 0x3000

using namespace std;

/********************************
 *     Virtual Machine Class    *
*********************************/

enum Register { 
    R0 = 0, R1, R2, R3, R4, 
    R5, R6, R7, PC, COND, COUNT 
};

enum OpCodes { 
    BR = 0, ADD, LD, ST, 
    JSR, AND, LDR, STR, 
    RTI, NOT, LDI, STI,
    JMP, RES, LEA, TRAP 
};
              
enum CondFlags {  
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */ 
};

class LauncherLC3;

class VirtualMachine {
    friend class LauncherLC3;
    private:
        uint16_t reg[LC3_REGISTER_COUNT];
        Buffer* mem;

        void add(const int instr);
        void ldi(const int instr);               // load indirectly
        void band(const int instr);              // bitwise and
        void bnot(const int instr);              // bitwise or
        void branch(const int instr);
        void jump(const int instr) { 
            uint16_t r1 = (instr >> 6) & 0x7;    // first operand
            reg[PC] = reg[r1]; 
        }
        void jsr(const int instr);
        void load(const int instr);
        void loadr(const int instr);             // load register  
        void loadea(const int instr);            // load effective address
        void store(const int instr);
        void storei(const int instr);
        void storer(const int instr);

        const bool isImmMode(const int instr) { return (instr >> 5) & 0x1; }  // is it in immediate mode?

        const uint16_t signExtend(const int16_t x, const int bit_count) {
            return (x >> (bit_count - 1) & 1) ? x | (0xFFFF << bit_count) : x;
        }
        const uint16_t offset(const int instr) { return signExtend(instr & 0x3F, 6); }
        const uint16_t pcoffset(const int instr) { return signExtend(instr & 0x1FF, 9); }
        const uint16_t longpcoffset(const int instr) { return signExtend(instr & 0x7FF, 11); }
        void           updateFlag(const uint16_t r);

        void       interrupt(int signal) { mem->interrupt(signal); }
        const bool read(char* path) { return mem->readPath(path); }

    public:
        VirtualMachine() { mem = static_cast<Buffer*>(new UnixBuffer()); }
        ~VirtualMachine() { delete mem; }
        void run();
};

/********************************
 *       Trap Helper Class      *
*********************************/

enum TrapCodes {
    GETC = 0x20,
    OUT = 0x21, 
    PUTS = 0x22,
    IN = 0x23,
    PUTSP = 0x24,
    HALT = 0x25
};

class Trap {
    private:
        Buffer* mem;
        uint16_t* reg;

        void getc() { *reg = (uint16_t) getchar(); }
        void out() { 
            putc((char) *reg, stdout);
            fflush(stdout);
        }
        void trputs();
        void in();
        void putsp();
        void halt(bool active);
    
    public:
        Trap(Buffer* m, uint16_t* r) : mem(m), reg(r) { }
        ~Trap() = default;
        void execute(const uint16_t instr, bool& active);
};

/********************************
 *      LC3 Launcher Class      *
*********************************/

class LauncherLC3 {
    private:
        static VirtualMachine vm;
        static void handleInterr(int signal) { LauncherLC3::vm.interrupt(signal); }

    public:
        LauncherLC3() = default;
        ~LauncherLC3() = default;
        void execute(int count, char* img[]);
};