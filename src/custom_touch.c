#include <stdio.h>
#include <stdlib.h>

void custom_touch(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file) {
        fclose(file);
        printf("File %s created successfully.\n", filename);
    } else {
        perror("touch");
    }
}
