#include <stdio.h>
#include <stdlib.h>

void custom_clear() {
    // Clear the screen (Linux/MacOS)
    printf("\033[H\033[J");
}
