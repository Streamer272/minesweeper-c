#ifndef MINESWEEPER_C_TERM
#define MINESWEEPER_C_TERM
#include <sys/ioctl.h>

typedef enum{UP, RIGHT, DOWN, LEFT, REVIELE, FLAG, NOTHING} Action;

extern struct winsize term_size;

void term_init();
void term_setup();
void term_reset();
Action term_take_input();

#endif
