#pragma once
#include <iostream>
#include <cstdint>

enum MemMapRegs { 
    MR_KBSR = 0xFE00, /* keyboard status */
    MR_KBDR = 0xFE02  /* keyboard data */
};

enum Trap {
    GETC = 0x20,
    OUT = 0x21, 
    PUTS = 0x22,
    IN = 0x23,
    PUTSP = 0x24,
    HALT = 0x25
};

class Buffer {
    private:
        uint16_t memory[UINT16_MAX];               // 65536 locations

        const uint16_t swap16(const uint16_t x) {  // switch from little to big Endian
            return (x << 8) | (x >> 8); 
        } 

    public:
        Buffer() = default;
        ~Buffer() = default;
        void write(const uint16_t addr, const uint16_t val) { memory[addr] = val; }
        const uint16_t read(const uint16_t address);
        void readImg(FILE* file);
        const bool readPath(const char* imgPath);
};