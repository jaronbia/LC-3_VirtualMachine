enum Register { R0 = 0, R1, R2, R3, R4, 
                R5, R6, R7, PC, COND, COUNT };

enum OpCode { BR = 0, ADD, LD, ST, 
              JSR, AND, LDR, STR, 
              RTI, NOT, LDI, STI,
              JMP, RES, LEA, TRAP };

class Emulator {
    private:
        uint16_t registers[11]

    public:

};