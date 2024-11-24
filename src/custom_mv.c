// custom_mv.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void custom_mv(char *source, char *destination) {
    // Check if source exists
    if (access(source, F_OK) == -1) {
        perror("Error");
        return;
    }

    // Try to rename (move) the file
    if (rename(source, destination) == -1) {
        perror("Error");
    } else {
        printf("File moved from %s to %s\n", source, destination);
    }
}
