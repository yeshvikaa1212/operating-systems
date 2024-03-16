#include <stdio.h>

#define MAX_BLOCKS 100

void allocateContiguous(int blocks[], int startBlock, int length) {
    printf("Allocating contiguous blocks for file...\n");
    for (int i = startBlock; i < startBlock + length; i++) {
        blocks[i] = 1; // Mark block as allocated
    }
}

void displayBlocks(int blocks[], int totalBlocks) {
    printf("Block Allocation Status:\n");
    for (int i = 0; i < totalBlocks; i++) {
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

int main() {
    int blocks[MAX_BLOCKS] = {0}; // Initialize all blocks as free

    int totalBlocks;
    printf("Enter total number of blocks in the file system: ");
    scanf("%d", &totalBlocks);

    int startBlock, length;
    printf("Enter starting block and length of the file: ");
    scanf("%d %d", &startBlock, &length);

    if (startBlock + length > totalBlocks) {
        printf("Error: File size exceeds available blocks.\n");
        return 1;
    }

    allocateContiguous(blocks, startBlock, length);
    displayBlocks(blocks, totalBlocks);

    return 0;
}

