#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

int findOptimal(int pages[], int n, int frame[], int frameSize) {
    int index = -1, farthest = 0;
    for (int i = 0; i < frameSize; i++) {
        int j;
        for (j = n; j >= 0; j--) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == -1)
            return i;
    }
    if (index == -1)
        return 0;
    return index;
}

void optimalPageReplace(int pages[], int n, int frameSize) {
    int frame[frameSize];
    int pageFaults = 0;

    for (int i = 0; i < frameSize; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            int pos = findOptimal(pages, i, frame, frameSize);
            frame[pos] = pages[i];
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 4;
    
    printf("Page reference string: ");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);
    printf("\n");

    optimalPageReplace(pages, n, frameSize);

    return 0;
}

