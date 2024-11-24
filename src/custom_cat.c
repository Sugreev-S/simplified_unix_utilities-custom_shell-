#include <stdio.h>
#include <stdlib.h>

void custom_cat(const char *filename) {
    if (filename == NULL) {
        printf("Usage: custom_cat <file>\n");
        return;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("custom_cat: Cannot open file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
