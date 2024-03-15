#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

void producer() {
    while (1) {
        if (count < BUFFER_SIZE) {
            int item = rand() % 100;
            buffer[in] = item;
            printf("Produced: %d\n", item);
            in = (in + 1) % BUFFER_SIZE;
            count++;
        }
    }
}

void consumer() {
    while (1) {
        if (count > 0) {
            int item = buffer[out];
            printf("Consumed: %d\n", item);
            out = (out + 1) % BUFFER_SIZE;
            count--;
        }
    }
}

int main() {
    producer();
    consumer();

    return 0;
}

