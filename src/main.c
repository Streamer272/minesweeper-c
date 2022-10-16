#include <stdio.h>
#include <stdlib.h>
#include "field.h"
#include "term.h"

#define FIELD_SIZE 64

int main() {
    Box* field = new_field(FIELD_SIZE);
    term_init();
    term_setup();
    display_field(field, FIELD_SIZE);

    printf("Hello World!\n");

    term_reset();
    return EXIT_SUCCESS;
}
