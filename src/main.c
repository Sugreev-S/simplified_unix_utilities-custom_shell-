#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"

void run_shell() {
    char command[256];
    char *args[3];  // Adjusted size for two commands and a pipe
    //char *command1, *command2;

    while (1) {
        printf("custom_shell> ");
        fgets(command, sizeof(command), stdin);

        // Tokenize the input command for piping
        int i = 0;
        args[i] = strtok(command, " \n");
        while (args[i] != NULL && i < 2) {
            i++;
            args[i] = strtok(NULL, " \n");
        }

        if (args[0] == NULL) {
            continue;
        }

        // Handling the pipe command
        // if (strcmp(args[0], "custom_pipe") == 0) {
        //     if (args[1] && args[2]) {
        //         // Split the input into two commands for piping
        //         command1 = args[1];
        //         command2 = args[2];

        //         custom_pipe(command1, command2);  // Call custom_pipe with two commands
        //     } else {
        //         printf("Usage: <command1> | <command2>\n");
        //     }
        if (strcmp(args[0], "c_ls") == 0) {
            if (args[1]) {
                custom_ls(args[1]);
            } else {
                custom_ls(".");  // Default to current directory if no argument is passed
            }
        } else if (strcmp(args[0], "c_cat") == 0) {
            if (args[1]) {
                custom_cat(args[1]);
            } else {
                printf("Usage: c_cat <filename>\n");
            }
        } else if (strcmp(args[0], "c_grep") == 0) {
            if (args[1] && args[2]) {
                custom_grep(args[1], args[2]);
            } else {
                printf("Usage: c_grep <pattern> <filename>\n");
            }
        } else if (strcmp(args[0], "c_wc") == 0) {
            if (args[1]) {
                custom_wc(args[1]);
            } else {
                printf("Usage: c_wc <filename>\n");
            }
        } else if (strcmp(args[0], "c_cp") == 0) {
            if (args[1] && args[2]) {
                custom_cp(args[1], args[2]);
            } else {
                printf("Usage: c_cp <source> <destination>\n");
            }
        } else if (strcmp(args[0], "c_mv") == 0) {
            if (args[1] && args[2]) {
                custom_mv(args[1], args[2]);
            } else {
                printf("Usage: c_mv <source> <destination>\n");
            }
        } else if (strcmp(args[0], "c_rm") == 0) {
            if (args[1]) {
                custom_rm(args[1]);
            } else {
                printf("Usage: c_rm <filename>\n");
            }
        } else if (strcmp(args[0], "c_cd") == 0) {
            if (args[1]) {
                custom_cd(args[1]);
            } else {
                printf("Usage: c_cd <path>\n");
            }
        } else if (strcmp(args[0], "c_clear") == 0) {
            custom_clear();
        } else if (strcmp(args[0], "c_whoami") == 0) {
            custom_whoami();
        } else if (strcmp(args[0], "c_echo") == 0) {
            if (args[1]) {
                custom_echo(args[1]);
            } else {
                printf("Usage: c_echo <text>\n");
            }
        } else if (strcmp(args[0], "c_touch") == 0) {
            if (args[1]) {
                custom_touch(args[1]);
            } else {
                printf("Usage: c_touch <filename>\n");
            }
        } else if (strcmp(args[0], "c_pwd") == 0) {
            custom_pwd();  
        } else if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", args[0]);
        }
    }
}

int main() {
    printf("Welcome to the Custom Shell!\n");
    printf("Available commands: custom_ls, custom_cat, custom_grep, custom_wc, custom_cp, custom_mv, custom_rm, custom_pipe, custom_cd, custom_clear, custom_whoami, custom_echo, custom_touch, exit\n");
    
    run_shell();
    
    return 0;
}
