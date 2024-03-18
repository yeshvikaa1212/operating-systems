#include <stdio.h>
#include <stdlib.h>

int main() {
    int ReadyQueue[100], i, n, TotalHeadMov = 0, initial;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ReadyQueue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    int next_index, max_distance, max_index;
    for (i = 0; i < n; i++) {
        max_distance = -1;
        for (int j = 0; j < n; j++) {
            int distance = abs(ReadyQueue[j] - initial);
            if (distance > max_distance) {
                max_distance = distance;
                next_index = j;
                max_index = j;
            }
        }
        TotalHeadMov += max_distance;
        initial = ReadyQueue[next_index];
        ReadyQueue[max_index] = -1; // Mark as visited
    }

    printf("Total Head Movement = %d\n", TotalHeadMov);

    return 0;
}

