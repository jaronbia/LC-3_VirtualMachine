#pragma once
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
        uint16_t memory[UINT16_MAX]; // 65536 locations 
        uint16_t reg[LC3_REGISTER_COUNT];

        void add(int instr);

        uint16_t signExtend(uint16_t x, int bit_count) {
            return (x >> (bit_count - 1)) & 1) 
                    ? x | (0xFFFF << bit_count) : x;
        }
        void updateFlag(uint16_t r) {
            if(reg[r] == 0) reg[COND] = FL_ZRO;
            else reg[COND] = (reg[r] >> 15) ? FL_NEG : FL_POS;
        }

    public:
        Emulator();
        ~Emulator() = default;
        void run();
};