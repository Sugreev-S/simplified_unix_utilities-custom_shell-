#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void custom_wc(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int lines = 0, words = 0, characters = 0;
    char ch;
    int in_word = 0;

    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        // Count lines
        if (ch == '\n') {
            lines++;
        }

        // Count words (by whitespace)
        if (isspace(ch)) {
            if (in_word) {
                in_word = 0;
                words++;
            }
        } else {
            in_word = 1;
        }
    }

    // If the last word wasn't followed by whitespace, count it
    if (in_word) {
        words++;
    }

    // Print the results in the standard `wc` format (lines, words, characters)
    printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, characters);

    fclose(file);
}
