#ifndef MINESWEEPER_C_FIELD
#define MINESWEEPER_C_FIELD
#include <malloc.h>

typedef enum{EMPTY, BOMB, REVIELED} Box;

Box* new_field(int size);
void display_field(Box* field, int size, int selected);
char get_box_value(Box* field, int index, int side);

#endif
