#include <stdio.h>

void executeProcess(int processes[], int burst_time[], int n) {
    int smallest_index = 0; // Initialize index of smallest burst time
    int smallest_burst_time = burst_time[0]; // Initialize smallest burst time

    // Find the process with the smallest burst time among waiting processes
    for (int i = 1; i < n; i++) {
        if (burst_time[i] < smallest_burst_time) {
            smallest_burst_time = burst_time[i];
            smallest_index = i;
        }
    }

    // Execute the process with the smallest burst time
    printf("Executing Process P%d\n", processes[smallest_index]);

    // Update burst time and mark the process as executed
    burst_time[smallest_index] = 0;
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Assigning process numbers
    }

    // Execute the waiting process with the smallest burst time
    executeProcess(processes, burst_time, n);

    return 0;
}

