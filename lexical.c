#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 256

int main() {
    FILE *fp, *fint, *fop, *fid;
    char c, id[MAX_ID_LEN];
    int i = 0;

    fp = fopen("input.txt", "r");
    fint = fopen("integers.txt", "w");
    fop = fopen("operators.txt", "w");
    fid = fopen("identifiers.txt", "w");

    if (fp == NULL) {
        printf("Cannot open file \n");
        return 0;
    }
    while ((c = fgetc(fp)) != EOF) {
        if (isdigit(c)) {
            fputc(c, fint);
            fputc('\n', fint);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            fputc(c, fop);
            fputc('\n', fop);
        } else if (isalnum(c)) {
            if (i < sizeof(id) - 1) {
                id[i++] = c;
            }
        } else {
            if (i > 0) {
                id[i] = '\0';
                fprintf("identifiers.txt", "%s\n", id);
                i = 0;
            }
        }
    }
    fclose(fp);
    fclose(fint);
    fclose(fop);
    fclose(fid);

    return 0;
}