#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[MAX_FRAMES];
    int page_faults = 0;

    for (int i = 0; i < MAX_FRAMES; ++i) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        int found = 0;

        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int lru_index = -1;
            int lru_time = n + 1;

            for (int j = 0; j < MAX_FRAMES; ++j) {
                int k;
                for (k = i - 1; k >= 0; --k) {
                    if (frames[j] == pages[k]) {
                        if (k < lru_time) {
                            lru_time = k;
                            lru_index = j;
                        }
                        break;
                    }
                }
                if (k == -1) {
                    lru_index = j;
                    break;
                }
            }

            frames[lru_index] = pages[i];
            page_faults++;
        }

        printf("Page %d: ", pages[i]);
        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
