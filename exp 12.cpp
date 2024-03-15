#include <stdio.h>
#include <string.h>

#define MAX_FILES_PER_DIRECTORY 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_DIRECTORIES 10

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
} File;

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    File files[MAX_FILES_PER_DIRECTORY];
    int numFiles;
} Directory;

typedef struct {
    Directory directories[MAX_DIRECTORIES];
    int numDirectories;
} FileSystem;

void createDirectory(FileSystem* fs, char* dirName) {
    if (fs->numDirectories < MAX_DIRECTORIES) {
        strcpy(fs->directories[fs->numDirectories].name, dirName);
        fs->directories[fs->numDirectories].numFiles = 0;
        fs->numDirectories++;
        printf("Directory \"%s\" created successfully.\n", dirName);
    } else {
        printf("Maximum directories reached. Cannot create directory \"%s\".\n", dirName);
    }
}

void addFileToDirectory(FileSystem* fs, char* dirName, char* fileName) {
    for (int i = 0; i < fs->numDirectories; i++) {
        if (strcmp(fs->directories[i].name, dirName) == 0) {
            if (fs->directories[i].numFiles < MAX_FILES_PER_DIRECTORY) {
                strcpy(fs->directories[i].files[fs->directories[i].numFiles].name, fileName);
                fs->directories[i].numFiles++;
                printf("File \"%s\" added to directory \"%s\".\n", fileName, dirName);
                return;
            } else {
                printf("Maximum files reached in directory \"%s\". Cannot add file \"%s\".\n", dirName, fileName);
                return;
            }
        }
    }
    printf("Directory \"%s\" not found. Cannot add file \"%s\".\n", dirName, fileName);
}

int main() {
    FileSystem fs = {0};

    createDirectory(&fs, "Documents");
    createDirectory(&fs, "Pictures");

    addFileToDirectory(&fs, "Documents", "report.txt");
    addFileToDirectory(&fs, "Pictures", "vacation.jpg");

    return 0;
}

