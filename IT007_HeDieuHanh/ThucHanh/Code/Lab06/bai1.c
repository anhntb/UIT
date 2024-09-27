#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

void parse_command(char *cmd, char **argv, int *argc) {
    char *token = strtok(cmd, " \t\r\n");
    *argc = 0;
    while (token != NULL) {
        argv[(*argc)++] = token;
        token = strtok(NULL, " \t\r\n");
    }
    argv[*argc] = NULL;
}

void execute_command(char **argv, int argc) {
    pid_t pid = fork();

    if (pid == 0) {  // Child process
        int in_redirect = -1, out_redirect = -1;
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "<") == 0) {
                in_redirect = i;
            } else if (strcmp(argv[i], ">") == 0) {
                out_redirect = i;
            }
        }

        if (in_redirect != -1) {
            int fd = open(argv[in_redirect + 1], O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(1);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
            argv[in_redirect] = NULL;
        }

        if (out_redirect != -1) {
            int fd = open(argv[out_redirect + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("open");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            argv[out_redirect] = NULL;
        }

        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    } else if (pid > 0) {  // Parent process
        wait(NULL);
    } else {
        perror("fork");
        exit(1);
    }
}

void execute_piped_commands(char *cmd) {
    char *commands[2];
    int cmd_count = 0;

    char *token = strtok(cmd, "|");
    while (token != NULL) {
        commands[cmd_count++] = token;
        token = strtok(NULL, "|");
    }

    if (cmd_count == 1) {
        char *argv[MAX_ARGS];
        int argc;
        parse_command(commands[0], argv, &argc);
        execute_command(argv, argc);
    } else if (cmd_count == 2) {
        int pipefd[2];
        if (pipe(pipefd) == -1) {
            perror("pipe");
            exit(1);
        }

        pid_t pid1 = fork();
        if (pid1 == 0) {  // First child process
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);

            char *argv[MAX_ARGS];
            int argc;
            parse_command(commands[0], argv, &argc);
            execvp(argv[0], argv);
            perror("execvp");
            exit(1);
        }

        pid_t pid2 = fork();
        if (pid2 == 0) {  // Second child process
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);

            char *argv[MAX_ARGS];
            int argc;
            parse_command(commands[1], argv, &argc);
            execvp(argv[0], argv);
            perror("execvp");
            exit(1);
        }

        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    }
}

int main() {
    char line[MAX_LINE];
    while (1) {
        printf("it007sh> ");
        if (!fgets(line, MAX_LINE, stdin)) break;

        if (strcmp(line, "exit\n") == 0) break;

        execute_piped_commands(line);
    }

    return 0;
}
