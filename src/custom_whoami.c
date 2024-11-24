#include <stdio.h>
#include <stdlib.h>

void custom_whoami() {
    char *user = getenv("USER");
    if (user) {
        printf("Current user: %s\n", user);
    } else {
        perror("whoami");
    }
}
