#include <stdio.h>

void fcfs(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];
  
    // Waiting time for the first process is 0
    waiting_time[0] = 0;

    // Calculating waiting time for each process
    for (int i = 1; i < n; i++)
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];

    // Calculating turnaround time for each process
    for (int i = 0; i < n; i++)
        turnaround_time[i] = waiting_time[i] + burst_time[i];

    // Displaying the process details
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
  
    // Calculating and displaying average waiting time and turnaround time
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Assigning process numbers
    }

    fcfs(processes, n, burst_time);

    return 0;
}

