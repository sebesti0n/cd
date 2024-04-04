#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file, *temp;
    char path[100];
    char ch;
    int count = 1, line;

    printf("\nEnter the source file's path: ");
    scanf("%s", path);

    printf("\nEnter the line number to be deleted: ");
    scanf("%d", &line);

    file = fopen(path, "r");
    temp = fopen("updated.tmp", "w");
    if(file == NULL || temp == NULL) {
        printf("\nUnable to open file!\n");
        exit(1);
    }

    printf("\nFile content before deleting:\n");
    while((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    rewind(file);

    char buffer[1000];
    while((fgets(buffer, 1000, file)) != NULL) {
        if(line != count) {
            fputs(buffer, temp);
        }
        count++;
    }

    fclose(file);
    fclose(temp);
    remove(path);
    rename("updated.tmp", path);

    printf("\nThe updated content of the file is:\n");
    file = fopen(path, "r");
    while((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    return 0;
}