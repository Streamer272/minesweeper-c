#include "field.h"
#include <stdio.h>

Box* new_field(int size) {
    Box* boxes = malloc(sizeof(Box) * size);
    for (int i = 0; i < size; i++) {
        boxes[i] = HIDDEN_EMPTY;
    }
    return boxes;
}

void display_field(Box* field, int size) {
    printf("display_field()\n");
}
