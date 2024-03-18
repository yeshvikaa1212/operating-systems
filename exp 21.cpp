#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

// Structure representing a disk block
typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
} Block;

// Function to create a new disk block
Block* createBlock() {
    Block* block = (Block*)malloc(sizeof(Block));
    if (block == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    block->next = NULL;
    return block;
}

// Function to simulate file allocation strategy
void simulateFileAllocation(int numBlocks) {
    Block* firstBlock = NULL;
    Block* lastBlock = NULL;

    // Create linked list of disk blocks
    for (int i = 0; i < numBlocks; i++) {
        Block* newBlock = createBlock();
        if (firstBlock == NULL) {
            firstBlock = newBlock;
            lastBlock = newBlock;
        } else {
            lastBlock->next = newBlock;
            lastBlock = newBlock;
        }
    }

    // Display information about allocated blocks
    printf("File allocated with linked allocation strategy.\n");
    printf("First block: %p\n", (void*)firstBlock);
    printf("Last block: %p\n", (void*)lastBlock);
}

int main() {
    int numBlocks;
    printf("Enter number of blocks for file allocation: ");
    scanf("%d", &numBlocks);

    if (numBlocks <= 0) {
        printf("Invalid number of blocks!\n");
        return 1;
    }

    simulateFileAllocation(numBlocks);

    return 0;
}

