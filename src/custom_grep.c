#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void custom_grep(const char *pattern, const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file for reading
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];  // Buffer to store each line
    int found = 0;    // Flag to track if any match is found
    while (fgets(line, sizeof(line), file)) {  // Read each line from the file
        if (strstr(line, pattern)) {  // If the pattern is found in the line
            printf("%s", line);  // Print the matching line
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found in %s\n", filename);  // If no match was found
    }

    fclose(file);  // Close the file after reading
}
