#include "UnixBuffer.hpp"

const uint16_t UnixBuffer::
checkKey() {
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    Timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    return select(1, &readfds, NULL, NULL, &timeout) != 0;
}

void UnixBuffer:: 
disableInput() {
    tcgetattr(STDIN_FILENO, &original_tio);
    Termios new_tio = original_tio;
    new_tio.c_lflag &= ~ICANON & ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void UnixBuffer:: 
interrupt(int signal) {
    char x = '\n';
    restoreInput();
    printf("%s", &x);
    exit(-2);
}