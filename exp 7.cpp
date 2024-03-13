#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    int fd[2]; // File descriptors for the pipe
    pid_t pid;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Create pipe
    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        close(fd[0]); // Close reading end of the pipe
        printf("Parent process writing to pipe...\n");
        // Write to the pipe
        write(fd[1], "Hello from parent process!", sizeof("Hello from parent process!"));
        close(fd[1]); // Close writing end of the pipe
    } else { // Child process
        close(fd[1]); // Close writing end of the pipe
        printf("Child process reading from pipe...\n");
        // Read from the pipe
        bytes_read = read(fd[0], buffer, BUFFER_SIZE);
        if (bytes_read > 0) {
            printf("Child process received message: %s\n", buffer);
        }
        close(fd[0]); // Close reading end of the pipe
    }

    return 0;
}

