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

    for (i = 0; i < n; i++) {
        TotalHeadMov += abs(ReadyQueue[i] - initial);
        initial = ReadyQueue[i];
    }

    printf("Total Head Movement = %d\n", TotalHeadMov);

    return 0;
}

