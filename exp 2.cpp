#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file, *destination_file;
    char source_filename[100], destination_filename[100], c;

    printf("Enter the source filename: ");
    scanf("%s", source_filename);

    printf("Enter the destination filename: ");
    scanf("%s", destination_filename);

    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("Error: Unable to open source file.\n");
        exit(EXIT_FAILURE);
    }

    destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL) {
        printf("Error: Unable to open destination file.\n");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(source_file)) != EOF) {
        fputc(c, destination_file);
    }

    printf("File copied successfully.\n");

    fclose(source_file);
    fclose(destination_file);

    return 0;
}

