#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(fd[0]); // Close unused read end
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe
        close(fd[1]); // Close used write end

        execlp("./pre", "pre", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else { // Child process
        close(fd[1]); // Close unused write end
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to pipe
        close(fd[0]); // Close used read end

        execlp("./sort", "sort", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
