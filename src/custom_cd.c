#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void custom_cd(const char *path) {
    if (chdir(path) == 0) {
        printf("Changed directory to: %s\n", path);
    } else {
        perror("cd");
    }
}
