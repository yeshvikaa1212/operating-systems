#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

// Function to find the index of the page in the frames array
int findPage(int page, int frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

// Function to find the index of the least recently used page in the frames array
int findLRUIndex(int counter[], int num_frames) {
    int min = counter[0];
    int index = 0;
    for (int i = 1; i < num_frames; i++) {
        if (counter[i] < min) {
            min = counter[i];
            index = i;
        }
    }
    return index;
}

// Function to simulate LRU page replacement algorithm
void lru(int pages[], int num_pages) {
    int frames[MAX_FRAMES];
    int counter[MAX_FRAMES];
    int num_frames = 0;
    int page_faults = 0;

    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int index = findPage(page, frames, num_frames);

        if (index == -1) { // Page fault
            if (num_frames < MAX_FRAMES) {
                frames[num_frames] = page;
                counter[num_frames] = i;
                num_frames++;
            } else {
                int lru_index = findLRUIndex(counter, num_frames);
                frames[lru_index] = page;
                counter[lru_index] = i;
            }
            page_faults++;
        } else { // Page hit
            counter[index] = i;
        }

        // Print current state of frames
        printf("Page %d -> Frames: ", page);
        for (int j = 0; j < num_frames; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES] = {1, 3, 0, 3, 5, 6, 3, 1, 0, 1};
    int num_pages = 10;
    lru(pages, num_pages);
    return 0;
}

