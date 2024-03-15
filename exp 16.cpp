#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if ((rear + 1) % QUEUE_SIZE == front) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % QUEUE_SIZE;
    queue[rear] = item;
    printf("Enqueued %d.\n", item);
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % QUEUE_SIZE;
    }
    printf("Dequeued %d.\n", item);
    return item;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70); // Queue is full at this point
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue is empty at this point

    return 0;
}

