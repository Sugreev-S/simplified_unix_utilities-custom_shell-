#include "utils.h"
#include <stdlib.h>
#include <string.h>

void split_input(char *input, char **args, int *arg_count) {
    char *token = strtok(input, " ");
    *arg_count = 0;

    while (token) {
        args[(*arg_count)++] = token;
        token = strtok(NULL, " ");
    }
    args[*arg_count] = NULL;
}

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
