#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "field.h"
#include "term.h"

#define FIELD_SIZE 64

int main() {
    Box* field = new_field(FIELD_SIZE);
    int selected = FIELD_SIZE / 2 + sqrt(FIELD_SIZE) / 2;
    int side = sqrt(FIELD_SIZE);
    bool running = true;
    term_init();
    term_setup();

    while (running) {
        display_field(field, FIELD_SIZE, selected);
        Action input = term_take_input();
        switch(input) {
        case UP:
            if (selected - side < 0) break;
            selected -= side;
            break;
        case RIGHT:
            if (selected + 1 >= FIELD_SIZE) break;
            selected++;
            break;
        case DOWN:
            if (selected + side >= FIELD_SIZE) break;
            selected += side;
            break;
        case LEFT:
            if (selected - 1 < 0) break;
            selected--;
            break;
        case REVIELE:
            if (field[selected] != EMPTY && field[selected] != BOMB)
                break;
            if (field[selected] != BOMB) {
                field[selected] = REVIELED;
                break;
            }
            field[selected] = REVIELED;
            display_field(field, FIELD_SIZE, selected);
            printf("It was a bomb, you lost!");
            exit(EXIT_SUCCESS);
            break;
        case FLAG:
            if (field[selected] == EMPTY)
                field[selected] = FLAGGED_EMPTY;
            else if (field[selected] == BOMB)
                field[selected] = FLAGGED_BOMB;
            else if (field[selected] == FLAGGED_BOMB)
                field[selected] = BOMB;
            else if (field[selected] == FLAGGED_EMPTY)
                field[selected] = EMPTY;
            break;
        }
        printf("\n");
    }

    term_reset();
    return EXIT_SUCCESS;
}
