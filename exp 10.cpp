#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 1000

// Memory block structure
typedef struct {
    int start;
    int size;
    bool allocated;
} MemoryBlock;

MemoryBlock memory[MEMORY_SIZE];

// Function to initialize memory
void initializeMemory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i].start = i;
        memory[i].size = 0;
        memory[i].allocated = false;
    }
}

// Function to allocate memory using first-fit algorithm
int allocateMemory(int size) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= size) {
            memory[i].size = size;
            memory[i].allocated = true;
            return memory[i].start;
        }
    }
    return -1; // Allocation failed
}

// Function to deallocate memory
void deallocateMemory(int start) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i].start == start) {
            memory[i].allocated = false;
            memory[i].size = 0;
            break;
        }
    }
}

int main() {
    initializeMemory();

    // Example: Allocate memory blocks
    int block1 = allocateMemory(200);
    int block2 = allocateMemory(300);

    // Example: Deallocate memory block 2
    deallocateMemory(block2);

    return 0;
}

