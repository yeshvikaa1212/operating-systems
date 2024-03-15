#include <stdio.h>
#include <stdbool.h>

#define NUM_RESOURCES 3
#define NUM_PROCESSES 5

int available[NUM_RESOURCES];
int maximum[NUM_PROCESSES][NUM_RESOURCES];
int allocation[NUM_PROCESSES][NUM_RESOURCES];
int need[NUM_PROCESSES][NUM_RESOURCES];
bool finish[NUM_PROCESSES];

bool isSafe(int process, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++)
        if (request[i] > need[process][i] || request[i] > available[i])
            return false;
    return true;
}

void allocateResources(int process, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
}

void releaseResources(int process, int request[]) {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] += request[i];
        allocation[process][i] -= request[i];
        need[process][i] += request[i];
    }
}

bool bankerAlgorithm() {
    int work[NUM_RESOURCES], count = 0;
    for (int i = 0; i < NUM_RESOURCES; i++)
        work[i] = available[i];
    for (int i = 0; i < NUM_PROCESSES; i++)
        finish[i] = false;
    while (count < NUM_PROCESSES) {
        bool canAllocate = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i] && isSafe(i, need[i])) {
                canAllocate = true;
                finish[i] = true;
                count++;
                for (int j = 0; j < NUM_RESOURCES; j++)
                    work[j] += allocation[i][j];
                break;
            }
        }
        if (!canAllocate)
            return false;
    }
    return true;
}

int main() {
    // Initialize available resources
    printf("Enter the number of available resources of each type:\n");
    for (int i = 0; i < NUM_RESOURCES; i++)
        scanf("%d", &available[i]);

    // Initialize maximum resources for each process
    printf("Enter the maximum demand of each resource type for each process:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("For process %d: ", i);
        for (int j = 0; j < NUM_RESOURCES; j++)
            scanf("%d", &maximum[i][j]);
    }

    // Simulation
    printf("Enter request for process number: ");
    int process;
    scanf("%d", &process);

    int request[NUM_RESOURCES];
    printf("Enter the request for process %d: ", process);
    for (int i = 0; i < NUM_RESOURCES; i++)
        scanf("%d", &request[i]);

    if (isSafe(process, request)) {
        allocateResources(process, request);
        if (bankerAlgorithm())
            printf("Request granted.\n");
        else {
            releaseResources(process, request);
            printf("Request denied. Granting it would lead to an unsafe state.\n");
        }
    } else
        printf("Request denied. Request exceeds maximum allowed.\n");

    return 0;
}

