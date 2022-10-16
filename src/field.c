#include "field.h"
#include <stdio.h>
#include <math.h>

Box* new_field(int size) {
    Box* boxes = malloc(sizeof(Box) * size);
    for (int i = 0; i < size; i++) {
        boxes[i] = EMPTY;
    }
    return boxes;
}

void display_field(Box* field, int size, int selected) {
    int side = (int) sqrt((double) size);
    for (int j = 0; j < side; j++) {
        for (int i = 0; i < side; i++) {
            printf("%c", get_box_value(field, j * side + i, side));
            if (i != side - 1) {
                if (j * side + i + 1 == selected)
                    printf("[");
                else if (j * side + i == selected)
                    printf("]");
                else
                    printf("|");
            }
            else
                printf("\n");
        }
    }
}

char get_box_value(Box* field, int index, int side) {
    switch (field[index]) {
    case EMPTY:
    case BOMB:
        return ' ';
    case REVIELED:
        int bombs_around = 0;
        if (index - side - 1 >= 0 && index % side != 0 && field[index - side - 1] == BOMB)
            bombs_around++;
        if (index - side >= 0 && field[index - side] == BOMB)
            bombs_around++;
        if (index - side + 1 >= 0 && index + 1 % side != 0 && field[index - side + 1] == BOMB)
            bombs_around++;
        if (index % side != 0 && field[index - 1] == BOMB)
            bombs_around++;
        if (index + 1 % side != 0 && field[index + 1] == BOMB)
            bombs_around++;
        if (index + side - 1 < pow(side, 2) && field[index + side - 1] == BOMB)
            bombs_around++;
        if (index + side < pow(side, 2) && field[index + side] == BOMB)
            bombs_around++;
        if (index + side + 1 < pow(side, 2) && index + 1 % side != 0 && field[index + side + 1] == BOMB)
            bombs_around++;
        return 0x30 + bombs_around;
    }
}
