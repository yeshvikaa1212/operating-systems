#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_PHILOSOPHERS 5
#define NUM_EAT_TIMES 3 // Number of times each philosopher will eat

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void* philosopher(void* arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    for (int i = 0; i < NUM_EAT_TIMES; i++) {
        printf("Philosopher %d is thinking\n", id);
        usleep(rand() % 1000000);  // thinking

        pthread_mutex_lock(&chopsticks[left]);
        pthread_mutex_lock(&chopsticks[right]);

        printf("Philosopher %d is eating\n", id);
        usleep(rand() % 1000000);  // eating

        pthread_mutex_unlock(&chopsticks[left]);
        pthread_mutex_unlock(&chopsticks[right]);
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    srand(time(NULL));  // Seed random number generator

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}

