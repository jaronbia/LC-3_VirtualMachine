#pragma once
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>
#include "Buffer.hpp"

typedef struct termios Termios;
typedef struct timeval Timeval;

class UnixBuffer : public Buffer {
    private:
        Termios original_tio;

    public:
        UnixBuffer() = default;
        ~UnixBuffer() = default;
        virtual const uint16_t checkKey() override;
        virtual void           disableInput() override;       // disable input buffering
        virtual void           restoreInput() override {      // restore input buffering
            tcsetattr(STDIN_FILENO, TCSANOW, &original_tio);
        }
        virtual void           interrupt(int signal) override;          // handle interrupt
};