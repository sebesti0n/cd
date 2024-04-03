#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    char path[100];
    char ch;
    int words = 0, lines = 0, characters = 0;

    printf("\nEnter the source file's path: ");
    scanf("%s", path);

    file = fopen(path, "r");
    if(file == NULL) {
        printf("\nUnable to open file!\n");
        exit(1);
    }
    while((ch = fgetc(file)) != EOF) {
        characters++;
        if(ch == '\n' || ch == '\0') {
            lines++;
        }
        if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
            words++;
        }
    }
    if(characters > 0) {
        words++;
        lines++;
    }
    printf("\nTotal characters:\t%d", characters);
    printf("\nTotal words:\t\t%d", words);
    printf("\nTotal lines:\t\t%d", lines);
    printf("\n");
    fclose(file);

    return 0;
}