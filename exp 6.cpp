#include <stdio.h>

#define MAX_PROCESS 10

// Function to implement Round Robin Scheduling
void roundRobin(int processes[], int n, int burst_time[], int quantum) {
    int remaining_time[MAX_PROCESS]; // Remaining burst time for each process
    int total_waiting_time = 0, total_turnaround_time = 0; // Total waiting and turnaround time

    // Copy burst times to remaining_time array
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    // Simulating the execution of processes
    int current_time = 0;
    while (1) {
        int done = 1; // Flag to check if all processes are done

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // If any process is remaining, set done to 0
                
                // Execute the process for the quantum or its remaining time, whichever is smaller
                if (remaining_time[i] > quantum) {
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    current_time += remaining_time[i];
                    total_waiting_time += current_time - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }

        if (done == 1) // If all processes are done, break the loop
            break;
    }

    // Calculating turnaround time
    for (int i = 0; i < n; i++)
        total_turnaround_time += burst_time[i] + total_waiting_time;

    // Displaying the process details
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], total_waiting_time, total_turnaround_time);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[MAX_PROCESS], burst_time[MAX_PROCESS];

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Assigning process numbers
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, burst_time, quantum);

    return 0;
}

