#include <stdio.h>
#include <stdlib.h>

void custom_rm(char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }
}
