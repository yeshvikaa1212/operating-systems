#include <stdio.h>

#define MAX_BLOCKS 100

void allocateIndexed(int indexBlock[], int fileBlocks[], int fileSize) {
    printf("Allocating blocks for file using indexed allocation...\n");
    for (int i = 0; i < fileSize; i++) {
        indexBlock[i] = fileBlocks[i]; // Store block pointer in index block
    }
}

void displayIndexBlock(int indexBlock[], int fileSize) {
    printf("Index Block:\n");
    for (int i = 0; i < fileSize; i++) {
        printf("%d -> %d\n", i, indexBlock[i]);
    }
}

int main() {
    int indexBlock[MAX_BLOCKS] = {0}; // Initialize index block
    int fileBlocks[MAX_BLOCKS] = {0}; // Initialize file blocks

    int fileSize;
    printf("Enter size of the file: ");
    scanf("%d", &fileSize);

    printf("Enter block pointers for the file:\n");
    for (int i = 0; i < fileSize; i++) {
        scanf("%d", &fileBlocks[i]);
    }

    allocateIndexed(indexBlock, fileBlocks, fileSize);
    displayIndexBlock(indexBlock, fileSize);

    return 0;
}

