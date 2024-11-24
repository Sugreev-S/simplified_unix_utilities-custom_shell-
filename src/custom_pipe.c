// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/wait.h>

// #define MAX_ARGS 10

// // Function to execute a command
// void execute_command(char *cmd, char **args) {
//     pid_t pid = fork();
//     if (pid == 0) {
//         // Child process
//         execvp(cmd, args);
//         perror("execvp failed");
//         exit(1);
//     } else if (pid < 0) {
//         perror("fork failed");
//         exit(1);
//     } else {
//         // Parent process waits for the child to finish
//         wait(NULL);
//     }
// }

// // Function to handle the pipe
// void custom_pipe(char *input) {
//     char *commands[2];
//     char *args1[MAX_ARGS], *args2[MAX_ARGS];
    
//     // Split input on the pipe symbol
//     char *token = strtok(input, "|");
//     int i = 0;
//     while (token != NULL && i < 2) {
//         commands[i++] = token;
//         token = strtok(NULL, "|");
//     }

//     if (i != 2) {
//         printf("Usage: <command1> | <command2>\n");
//         return;
//     }

//     // Tokenize the first command and its arguments
//     char *cmd1 = strtok(commands[0], " \n");
//     int j = 0;
//     while (cmd1 != NULL) {
//         args1[j++] = cmd1;
//         cmd1 = strtok(NULL, " \n");
//     }
//     args1[j] = NULL;  // NULL-terminate the arguments

//     // Tokenize the second command and its arguments
//     char *cmd2 = strtok(commands[1], " \n");
//     int k = 0;
//     while (cmd2 != NULL) {
//         args2[k++] = cmd2;
//         cmd2 = strtok(NULL, " \n");
//     }
//     args2[k] = NULL;  // NULL-terminate the arguments

//     // Create a pipe
//     int pipe_fd[2];
//     if (pipe(pipe_fd) == -1) {
//         perror("pipe failed");
//         exit(1);
//     }

//     pid_t pid1 = fork();
//     if (pid1 == 0) {
//         // First child process
//         close(pipe_fd[0]);  // Close read end of the pipe
//         dup2(pipe_fd[1], STDOUT_FILENO);  // Redirect stdout to pipe
//         close(pipe_fd[1]);
        
//         // If the first command is 'custom_ls', use '.' as argument
//         if (strcmp(args1[0], "custom_ls") == 0) {
//             args1[1] = ".";  // Provide the current directory as the argument
//         }
        
//         execvp(args1[0], args1);  // Execute the first command
//         perror("execvp failed");
//         exit(1);
//     }

//     pid_t pid2 = fork();
//     if (pid2 == 0) {
//         // Second child process
//         close(pipe_fd[1]);  // Close write end of the pipe
//         dup2(pipe_fd[0], STDIN_FILENO);  // Redirect stdin from pipe
//         close(pipe_fd[0]);

//         // If the second command is 'custom_grep', handle the pattern and file arguments
//         if (strcmp(args2[0], "custom_grep") == 0 && args2[1] != NULL && args2[2] != NULL) {
//             // Ensure the pattern and file are properly set for grep
//             execvp(args2[0], args2);  // Execute the second command
//         }

//         perror("execvp failed");
//         exit(1);
//     }

//     // Parent process closes both ends of the pipe
//     close(pipe_fd[0]);
//     close(pipe_fd[1]);

//     // Wait for both child processes to finish
//     wait(NULL);
//     wait(NULL);
// }
