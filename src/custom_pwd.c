#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void custom_pwd() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current directory: %s\n", cwd);
    } else {
        perror("custom_pwd");
    }
}
