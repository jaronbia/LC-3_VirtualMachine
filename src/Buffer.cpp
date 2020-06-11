#include "Buffer.hpp"

const uint16_t Buffer:: 
read(const uint16_t addr) {
    if (addr == MR_KBSR) {
        if (check_key()) {
            memory[MR_KBSR] = (1 << 15);
            memory[MR_KBDR] = getchar();
        }
        else {
            memory[MR_KBSR] = 0;
        }
    }

    return memory[addr];
}

void Buffer:: 
readImg(FILE* file) {
    /* the origin tells us where in memory to place the image */
    uint16_t origin;
    fread(&origin, sizeof(origin), 1, file);
    origin = swap16(origin);

    /* we know the maximum file size so we only need one fread */
    uint16_t max_read = UINT16_MAX - origin;
    uint16_t* p = memory + origin;
    size_t read = fread(p, sizeof(uint16_t), max_read, file);

    for( ; read > 0; --read, ++p) *p = swap16(*p);
}

const bool Buffer:: 
readPath(const char* imgPath) {
    FILE* file = fopen(imgPath, "rb");
    if (!file) return false;
    readImg(file);
    fclose(file);
    return true;
}