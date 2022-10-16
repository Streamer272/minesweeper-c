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

Action term_take_input() {
    int input = getchar();
    switch(input) {
    case 'q':
        printf("Are you sure you want to quit? (y/n) ");
        if (getchar() != 'n')
            exit(EXIT_SUCCESS);
    case 'A':
    case 'w':
        return UP;
    case 'C':
    case 'd':
        return RIGHT;
    case 'B':
    case 's':
        return DOWN;
    case 'D':
    case 'a':
        return LEFT;
    case ' ':
    case '\n':
        return REVIELE;
    case 'f':
        return FLAG;
    default:
        return NOTHING;
    }
}
