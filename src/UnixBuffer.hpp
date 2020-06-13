#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

/* unix */
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>
#include "Buffer.hpp"

typedef struct termios Termios;

class UnixBuffer : protected Buffer {
    private:
        Termios original_tio;

    public:
}