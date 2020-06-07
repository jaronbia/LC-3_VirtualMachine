#pragma once
#include <cstdint>
#define LC3_REGISTER_COUNT 11
#define PC_START 0x3000

using namespace std;

enum Register { R0 = 0, R1, R2, R3, R4, 
                R5, R6, R7, PC, COND, COUNT };

enum OpCode { BR = 0, ADD, LD, ST, 
              JSR, AND, LDR, STR, 
              RTI, NOT, LDI, STI,
              JMP, RES, LEA, TRAP };
              
enum CondFlags {  FL_POS = 1 << 0, /* P */
                  FL_ZRO = 1 << 1, /* Z */
                  FL_NEG = 1 << 2, /* N */ };

class Emulator {
    private:
        uint16_t memory[UINT16_MAX];             // 65536 locations 
        uint16_t reg[LC3_REGISTER_COUNT];

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

        bool isImmMode(const int instr) { return (instr >> 5) & 0x1; }  // is it in immediate mode?

        uint16_t signExtend(const int16_t x, const int bit_count) {
            return (x >> (bit_count - 1) & 1) ? x | (0xFFFF << bit_count) : x;
        }
        uint16_t offset(const int instr) { return signExtend(instr & 0x3F, 6); }
        uint16_t pcoffset(const int instr) { return signExtend(instr & 0x1FF, 9); }
        uint16_t longpcoffset(const int instr) { return signExtend(instr & 0x7FF, 11); }

        void updateFlag(uint16_t r) {
            if(reg[r] == 0) reg[COND] = FL_ZRO;
            else reg[COND] = (reg[r] >> 15) ? FL_NEG 
                                            : FL_POS;
        }

    public:
        Emulator();
        ~Emulator() = default;
        void run();
};