#ifndef MINESWEEPER_C_FIELD
#define MINESWEEPER_C_FIELD
#include <malloc.h>

typedef enum{HIDDEN_EMPTY, HIDDEN_BOMB, REVIELED} Box;

Box* new_field(int size);
void display_field(Box* field, int size);

#endif
