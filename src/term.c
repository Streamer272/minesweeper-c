#include "term.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct winsize term_size;
struct termios term;

void term_init() {
    tcgetattr(STDIN_FILENO, &term);

    if (isatty(STDOUT_FILENO) == 0) {
        term_size.ws_col = 80;
        term_size.ws_row = 80;
        return;
    }

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);
    if (term_size.ws_col == 0) {
        fprintf(stderr, "Couldn't get terminal size\n");
        exit(EXIT_FAILURE);
    }
}

void term_setup() {
    struct termios info;
    tcgetattr(STDIN_FILENO, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &info);
}

void term_reset() {
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
