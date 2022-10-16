#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "field.h"
#include "term.h"

#define FIELD_SIZE 16

int main() {
    Box* field = new_field(FIELD_SIZE);
    int selected = FIELD_SIZE / 2 + sqrt(FIELD_SIZE) / 2;
    term_init();
    term_setup();
    display_field(field, FIELD_SIZE, selected);

while (true) {
        Action input = term_take_input();
        printf("action is %d\n", input);
    }

    term_reset();
    return EXIT_SUCCESS;
}
