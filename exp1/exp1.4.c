#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file1, *file2;
    char path[100];

    printf("\nEnter the path of source file: ");
    scanf("%s", path);
    file1 = fopen(path, "r");
    if(file1 == NULL) {
        printf("\nUnable to open file!\n");
        exit(1);
    }

    printf("\nEnter the path for destination file: ");
    scanf("%s", path);
    file2 = fopen(path, "w");
    if(file2 == NULL) {
        printf("\nUnable to open file!\n");
        exit(1);
    }

    char ch;
    ch = fgetc(file1);
    while(ch != EOF) {
        fputc(ch, file2);
        ch = fgetc(file1);
    }
    fclose(file1);
    fclose(file2);

    return 0;
}