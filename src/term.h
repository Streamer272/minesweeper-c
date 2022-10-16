#ifndef MINESWEEPER_C_TERM
#define MINESWEEPER_C_TERM
#include <sys/ioctl.h>

extern struct winsize term_size;

void term_init();
void term_setup();
void term_reset();

#endif
