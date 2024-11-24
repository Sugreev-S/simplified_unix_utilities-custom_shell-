#include <stdio.h>
#include <stdlib.h>

void custom_cp(const char *source, const char *destination) {
    if (source == NULL || destination == NULL) {
        printf("Usage: custom_cp <source> <destination>\n");
        return;
    }

    FILE *src = fopen(source, "r");
    if (src == NULL) {
        perror("custom_cp: Cannot open source file");
        return;
    }

    FILE *dest = fopen(destination, "w");
    if (dest == NULL) {
        perror("custom_cp: Cannot create destination file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        if (fwrite(buffer, 1, bytes, dest) != bytes) {
            perror("custom_cp: Error writing to destination file");
            fclose(src);
            fclose(dest);
            return;
        }
    }

    printf("File copied successfully from %s to %s\n", source, destination);

    fclose(src);
    fclose(dest);
}
