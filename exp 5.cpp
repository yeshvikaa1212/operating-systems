#include <stdio.h>

void executeHighestPriorityProcess(int processes[], int priority[], int n) {
    int highest_priority_index = 0; // Initialize index of highest priority process
    int highest_priority = priority[0]; // Initialize highest priority

    // Find the process with the highest priority among waiting processes
    for (int i = 1; i < n; i++) {
        if (priority[i] < highest_priority) {
            highest_priority = priority[i];
            highest_priority_index = i;
        }
    }

    // Execute the process with the highest priority
    printf("Executing Process P%d\n", processes[highest_priority_index]);

    // Remove the executed process from the list
    for (int i = highest_priority_index; i < n - 1; i++) {
        processes[i] = processes[i + 1];
        priority[i] = priority[i + 1];
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], priority[n];

    printf("Enter priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &priority[i]);
        processes[i] = i + 1; // Assigning process numbers
    }

    // Execute the waiting process with the highest priority
    executeHighestPriorityProcess(processes, priority, n);

    return 0;
}

