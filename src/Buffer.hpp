#pragma once
#include <iostream> // #include <cstdio> 
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <csignal>

using namespace std;

enum MemMapRegs { 
    MR_KBSR = 0xFE00,                               // keyboard status 
    MR_KBDR = 0xFE02                                // keyboard data 
};

class Buffer {
    private:
        uint16_t memory[UINT16_MAX];               // 65536 locations

        const uint16_t swap16(const uint16_t x) {  // switch from little to big Endian
            return (x << 8) | (x >> 8); 
        }

    public:
        Buffer() = default;
        ~Buffer() = default; /* MAY NEED TO BECOME VIRTUAL */
        void           write(const uint16_t addr, const uint16_t val) { memory[addr] = val; }
        const uint16_t read(const uint16_t addr);
        void           readImg(FILE* file);
        const bool     readPath(const char* imgPath);
        uint16_t*      loc(const uint16_t* reg) { return memory + *reg; }

        virtual const uint16_t checkKey() = 0;
        virtual void           disableInput() = 0;       // disable input buffering
        virtual void           restoreInput() = 0;       // restore input buffering
        virtual void           interrupt() = 0;       // handle interrupt
};