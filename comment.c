#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    char input_path[100], output_path[100];
    printf("\nEnter the input file path: ");
    scanf("%s", input_path);
    printf("\nEnter the output file path: ");
    scanf("%s", output_path);

    input = fopen(input_path, "r");
    output = fopen(output_path, "w");
    if(input == NULL || output == NULL) {
        printf("\nUnable to open file!\n");
        exit(1);
    }
    char ch;
    while((ch = fgetc(input)) != EOF) {
        if(ch == '/') {
            ch = fgetc(input);
            if(ch == '/') {
                while((ch = fgetc(input))!= '\n') {
                    fputc(ch, output);
                }
                fputc('\n', output);
            }
            if(ch == '*') {
                LABLE:
                ch = fgetc(input);
                while((ch = fgetc(input)) != '*') {
                    fputc(ch, output);
                }
                ch = fgetc(input);
                if(ch == '/') {
                    ch = fgetc(input);
                    fputc('\n', output);
                } else {
                    fputc('*', output);
                    fputc(ch, output);
                    goto LABLE;
                }
            }
        }
    }
    fclose(input);
    fclose(output);
    printf("\nComments are written in the output file.\n");
    return 0;
}