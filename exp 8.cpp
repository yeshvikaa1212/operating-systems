#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by threads
void *threadFunction(void *arg) {
    char *message = (char *)arg;
    printf("%s\n", message);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2; // Thread identifiers

    char *message1 = "Thread 1 is executing";
    char *message2 = "Thread 2 is executing";

    // Create thread 1
    if (pthread_create(&tid1, NULL, threadFunction, (void *)message1) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Create thread 2
    if (pthread_create(&tid2, NULL, threadFunction, (void *)message2) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Wait for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

