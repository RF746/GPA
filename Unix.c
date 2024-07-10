#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        printf("Parent PID: %d\n", getpid());
        printf("Waiting for child process to terminate...\n");
        wait(NULL);
        printf("Child process terminated.\n");
    } else { // Child process
        printf("Child PID: %d\n", getpid());
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
